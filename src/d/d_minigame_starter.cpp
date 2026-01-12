/**
 * d_minigame_starter.cpp
 * Boating Course - "3-2-1 GO!" text
 */

#include "d/dolzel.h" // IWYU pragma: keep
#include "d/d_minigame_starter.h"
#include "JSystem/J2DGraph/J2DOrthoGraph.h"
#include "d/d_priority.h"
#include "d/d_procname.h"
#include "f_op/f_op_msg.h"
#include "f_op/f_op_msg_mng.h"

static s16 cdFrame0 = 0x0007;
static s16 cdFrame1 = 0x0003;
static s16  tmFrame = 0x0005;
static s16 cdFrame2 = 0x000F;
static s16 cdFrame3 = 0x0005;
static s16 cdFrame4 = 0x0007;
static s16 cdFrame5 = 0x0003;
static s16 cdFrame6 = 0x0004;
static s16 cdFrame7 = 0x0004;
static s16 cdFrame8 = 0x0006;

static s16 dMinigame_Starter_tex_number = 0x0003;

/* 80205FE8-80206124       .text _create__19dMinigame_Starter_cFv */
cPhs_State dMinigame_Starter_c::_create() {
    cPhs_State result = dComIfG_resLoad(&field_0x100, "Mgst");
    if (result == cPhs_COMPLEATE_e) {
        dRes_info_c* resInfo = dComIfG_getObjectResInfo("Mgst");
        JUT_ASSERT(86, resInfo != NULL);
        field_0x108 = mDoExt_createSolidHeapFromGameToCurrent(0x14C0, 0x20);

        if (field_0x108) {
            field_0x0FC = new dDlst_StarterScrnDraw_c();
            field_0x0FC->setScreen("ship_race1.blo", resInfo->getArchive());
            mDoExt_restoreCurrentHeap();
            mDoExt_adjustSolidHeap(field_0x108);
        } else {
            return cPhs_ERROR_e;
        }
    } else {
        return result;
    }

    field_0x111 = false;
    field_0x10C = 0;
    field_0x10E = 3;

    return cPhs_COMPLEATE_e;
}

/* 80206124-8020629C       .text _execute__19dMinigame_Starter_cFv */
BOOL dMinigame_Starter_c::_execute() {
    // TODO: Resolve fake matches in this function
    s32 temp_r30 = cdFrame0 + cdFrame1 + tmFrame + cdFrame2 + cdFrame3 - 0x1E;
    s32 temp_r29 = cdFrame4 + cdFrame5 + cdFrame6 + cdFrame7 + cdFrame8 - 0x17;

    if (field_0x111 == 0) {
        return FALSE;
    }

    if (field_0x10C < fake(temp_r29, temp_r30 * 3 + 0x89)) {
        field_0x10C++;
        if (field_0x10C >= fake(temp_r30 * 3 + 0x59, temp_r29)) {
            field_0x111 = 2;
        }
    } else {
        field_0x111 = 3;
    }

    if (field_0x10C <= fake(temp_r30, 0x1E)) {
        field_0x0FC->anime1(2);
    }

    if (field_0x10C >= fake(temp_r30, 0x1C) && field_0x10C <= fake(temp_r30 * 2, 0x39)) {
        field_0x0FC->anime1(1);
    }

    if (field_0x10C >= fake(temp_r30 * 2, 0x37) && field_0x10C <= fake(temp_r30 * 3, 0x54)) {
        field_0x0FC->anime1(0);
    }
    
    if (field_0x10C >= fake(temp_r30 * 3, 0x54) && field_0x10C <= fake(temp_r30 * 3 + 0x6B, temp_r29)) {
        field_0x0FC->anime2();
    }

    return TRUE;
}

/* 8020629C-802062DC       .text _draw__19dMinigame_Starter_cFv */
BOOL dMinigame_Starter_c::_draw() {
    dComIfGd_set2DOpa(field_0x0FC);
    return TRUE;
}

/* 802062DC-80206328       .text _delete__19dMinigame_Starter_cFv */
BOOL dMinigame_Starter_c::_delete() {
    if (field_0x108) {
        mDoExt_destroySolidHeap(field_0x108);
    }
    dComIfG_resDelete(&field_0x100, "Mgst");
    return TRUE;
}

/* 80206328-8020634C       .text startCheck__19dMinigame_Starter_cFv */
BOOL dMinigame_Starter_c::startCheck() {
    return field_0x111 == 3 || field_0x111 == 2;
}

/* 8020634C-80206360       .text deleteCheck__19dMinigame_Starter_cFv */
BOOL dMinigame_Starter_c::deleteCheck() {
    return field_0x111 == 3;
}

/* 80206360-802064DC       .text setScreen__23dDlst_StarterScrnDraw_cFPCcP10JKRArchive */
void dDlst_StarterScrnDraw_c::setScreen(const char* param_1, JKRArchive* param_2) {
    /* Apparent match, .data offsets */
    static u32 label_t[] = {
        'gog',
	    'goo',
	    'goex'
    };
    field_0x004 = new J2DScreen();
    field_0x004->set(param_1, param_2);
    for (int i = 0; i < dMinigame_Starter_tex_number; i++) {
        fopMsgM_setPaneData(&field_0x008[i], field_0x004, label_t[i]);
    }

    fopMsgM_setPaneData(&field_0x190, field_0x004, 'dmgo');

    fopMsgM_setPaneData(&field_0x1C8[0], field_0x004, 'go1');
    fopMsgM_setPaneData(&field_0x1C8[1], field_0x004, 'go2');
    fopMsgM_setPaneData(&field_0x1C8[2], field_0x004, 'go3');
    
    fopMsgM_setPaneData(&field_0x270[0], field_0x004, 'go12');
    fopMsgM_setPaneData(&field_0x270[1], field_0x004, 'go22');
    fopMsgM_setPaneData(&field_0x270[2], field_0x004, 'go32');
}

/* 802064DC-80206908       .text anime1__23dDlst_StarterScrnDraw_cFi */
bool dDlst_StarterScrnDraw_c::anime1(int param_1) {
    /* Nonmatching, regalloc */
    s16 frame_acc_1;
    s16 frame_acc_0;
    bool result;
    s16 frame_acc_t;
    s16 frame_acc_2;
    s16 frame_acc_3;

    f32 var_f1 = -8.0f;
    result = false;
    
    frame_acc_0 = cdFrame0;
    frame_acc_1 = frame_acc_0 + cdFrame1;
    frame_acc_t = frame_acc_1 + tmFrame;
    frame_acc_2 = frame_acc_t + cdFrame2;
    frame_acc_3 = frame_acc_2 + cdFrame3;

    field_0x1C8[param_1].mUserArea++;
    if (field_0x1C8[param_1].mUserArea <= frame_acc_0) {
        fopMsgM_paneScaleXY(
            &field_0x270[param_1], 
            acc(frame_acc_1, field_0x1C8[param_1].mUserArea, 0) * 0.3f + 0.7f
        );
        fopMsgM_setNowAlpha(
            &field_0x270[param_1], 
            acc(frame_acc_0, field_0x1C8[param_1].mUserArea, 0)
        );
    } else if (field_0x1C8[param_1].mUserArea <= frame_acc_1) {
        f32 y = acc(frame_acc_1, field_0x1C8[param_1].mUserArea, frame_acc_0);
        fopMsgM_paneScaleXY(&field_0x1C8[param_1], y * 0.3f + 0.7f);
        fopMsgM_setNowAlpha(&field_0x1C8[param_1], y);
        fopMsgM_paneScaleXY(
            &field_0x270[param_1], 
            acc(frame_acc_1, field_0x1C8[param_1].mUserArea, 0) * 0.3f + 0.7f
        );
        fopMsgM_setNowAlpha(&field_0x270[param_1], 1.0f - y);
        if (field_0x1C8[param_1].mUserArea == frame_acc_0) {
            mDoAud_seStart(JA_SE_SGAME_COUNTDOWN);
        }
    } else if (field_0x1C8[param_1].mUserArea > frame_acc_t) {
        if (field_0x1C8[param_1].mUserArea <= frame_acc_2) {
            if (((field_0x1C8[param_1].mUserArea - frame_acc_t) / ((frame_acc_2 - frame_acc_t) / 4)) % 2 != 0) {
                var_f1 *= -1.0f;
            }
            setRotate(&field_0x1C8[param_1], var_f1);
        } else if (field_0x1C8[param_1].mUserArea < frame_acc_3) {
            fopMsgM_paneScaleXY(&field_0x1C8[param_1], 1.0f + 2.0f * acc(frame_acc_3, field_0x1C8[param_1].mUserArea, frame_acc_2));
            fopMsgM_setNowAlpha(&field_0x1C8[param_1], 1.0f - acc(frame_acc_3, field_0x1C8[param_1].mUserArea, frame_acc_2));
        } else {
            fopMsgM_paneScaleXY(&field_0x1C8[param_1], 3.0f);
            fopMsgM_setNowAlphaZero(&field_0x1C8[param_1]);
            result = true;
        }
    }
    return result;
}

/* 80206908-80206CB0       .text anime2__23dDlst_StarterScrnDraw_cFv */
void dDlst_StarterScrnDraw_c::anime2() {
    /* Nonmatching */
}

/* 80206CB0-80206DA4       .text scaleAnime__23dDlst_StarterScrnDraw_cFf */
void dDlst_StarterScrnDraw_c::scaleAnime(f32 param_1) {
    field_0x190.mSize.x = field_0x190.mSizeOrig.x * param_1;
    field_0x190.mSize.y = field_0x190.mSizeOrig.y * param_1;
    
    for (int i = 0; i < dMinigame_Starter_tex_number; i++) {
        field_0x008[i].mSize.x = field_0x008[i].mSizeOrig.x * param_1;
        field_0x008[i].mSize.y = field_0x008[i].mSizeOrig.y * param_1;
    }

    field_0x190.mPosCenter = field_0x190.mPosCenterOrig;
    fopMsgM_cposMove(&field_0x190);

    for (int i = 0; i < dMinigame_Starter_tex_number; i++) {
        field_0x008[i].mPosCenter.x = field_0x008[i].mPosCenterOrig.x * param_1;
        field_0x008[i].mPosCenter.y = field_0x008[i].mPosCenterOrig.y * param_1;
        fopMsgM_cposMove(&field_0x008[i]);
    }
}

/* 80206DA4-80206E44       .text setRotate__23dDlst_StarterScrnDraw_cFP18fopMsgM_pane_classf */
void dDlst_StarterScrnDraw_c::setRotate(fopMsgM_pane_class* param_1, f32 param_2) {
    param_1->pane->rotate(
        (s32)(param_1->mSize.x / 2), 
        (s32)(param_1->mSize.y / 2), 
        ROTATE_Z, 
        param_2
    );
}

/* 80206E44-80206EDC       .text draw__23dDlst_StarterScrnDraw_cFv */
void dDlst_StarterScrnDraw_c::draw() {
    fopMsgM_setAlpha(&field_0x008[0]);
    for (int i = 0; i < ARRAY_SSIZE(field_0x1C8); i++) {
        fopMsgM_setAlpha(&field_0x1C8[i]);
        fopMsgM_setAlpha(&field_0x270[i]);
    }
    J2DOrthoGraph* graf_p = dComIfGp_getCurrentGrafPort();
    graf_p->setPort();
    field_0x004->draw(0.0f, 0.0f, graf_p);
}

/* 80206EDC-80206EFC       .text dMinigame_Starter_Draw__FP19dMinigame_Starter_c */
static BOOL dMinigame_Starter_Draw(dMinigame_Starter_c* i_this) {
    return i_this->_draw();
}

/* 80206EFC-80206F1C       .text dMinigame_Starter_Execute__FP19dMinigame_Starter_c */
static BOOL dMinigame_Starter_Execute(dMinigame_Starter_c* i_this) {
    return i_this->_execute();
}

/* 80206F1C-80206F24       .text dMinigame_Starter_IsDelete__FP19dMinigame_Starter_c */
static BOOL dMinigame_Starter_IsDelete(dMinigame_Starter_c*) {
    return TRUE;
}

/* 80206F24-80206F44       .text dMinigame_Starter_Delete__FP19dMinigame_Starter_c */
static BOOL dMinigame_Starter_Delete(dMinigame_Starter_c* i_this) {
    return i_this->_delete();
}

/* 80206F44-80206F64       .text dMinigame_Starter_Create__FP9msg_class */
static cPhs_State dMinigame_Starter_Create(msg_class* i_this) {
    return ((dMinigame_Starter_c*)i_this)->_create();
}

msg_method_class l_dMinigame_Starter_Method = {
    (process_method_func)dMinigame_Starter_Create,
    (process_method_func)dMinigame_Starter_Delete,
    (process_method_func)dMinigame_Starter_Execute,
    (process_method_func)dMinigame_Starter_IsDelete,
    (process_method_func)dMinigame_Starter_Draw,
};

msg_process_profile_definition g_profile_MINIGAME_STARTER = {
    /* LayerID      */ fpcLy_CURRENT_e,
    /* ListID       */ 12,
    /* ListPrio     */ fpcPi_CURRENT_e,
    /* ProcName     */ PROC_MINIGAME_STARTER,
    /* Proc SubMtd  */ &g_fpcLf_Method.base,
    /* Size         */ sizeof(dMinigame_Starter_c),
    /* SizeOther    */ 0,
    /* Parameters   */ 0,
    /* Leaf SubMtd  */ &g_fopMsg_Method,
    /* Priority     */ PRIO_MINIGAME_STARTER,
    /* Msg SubMtd   */ &l_dMinigame_Starter_Method,
};
