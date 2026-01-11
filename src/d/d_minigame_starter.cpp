/**
 * d_minigame_starter.cpp
 * Boating Course - "3-2-1 GO!" text
 */

#include "d/dolzel.h" // IWYU pragma: keep
#include "d/d_minigame_starter.h"
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

/* 80205FE8-80206124       .text _create__19dMinigame_Starter_cFv */
cPhs_State dMinigame_Starter_c::_create() {
    /* Nonmatching */
}

/* 80206124-8020629C       .text _execute__19dMinigame_Starter_cFv */
BOOL dMinigame_Starter_c::_execute() {
    /* Nonmatching */
}

/* 8020629C-802062DC       .text _draw__19dMinigame_Starter_cFv */
BOOL dMinigame_Starter_c::_draw() {
    /* Nonmatching */
}

/* 802062DC-80206328       .text _delete__19dMinigame_Starter_cFv */
BOOL dMinigame_Starter_c::_delete() {
    /* Nonmatching */
}

/* 80206328-8020634C       .text startCheck__19dMinigame_Starter_cFv */
BOOL dMinigame_Starter_c::startCheck() {
    /* Nonmatching */
}

/* 8020634C-80206360       .text deleteCheck__19dMinigame_Starter_cFv */
BOOL dMinigame_Starter_c::deleteCheck() {
    /* Nonmatching */
}

/* 80206360-802064DC       .text setScreen__23dDlst_StarterScrnDraw_cFPCcP10JKRArchive */
void dDlst_StarterScrnDraw_c::setScreen(const char*, JKRArchive*) {
    /* Nonmatching */
}

/* 802064DC-80206908       .text anime1__23dDlst_StarterScrnDraw_cFi */
void dDlst_StarterScrnDraw_c::anime1(int) {
    /* Nonmatching */
}

/* 80206908-80206CB0       .text anime2__23dDlst_StarterScrnDraw_cFv */
void dDlst_StarterScrnDraw_c::anime2() {
    /* Nonmatching */
}

/* 80206CB0-80206DA4       .text scaleAnime__23dDlst_StarterScrnDraw_cFf */
void dDlst_StarterScrnDraw_c::scaleAnime(f32) {
    /* Nonmatching */
}

/* 80206DA4-80206E44       .text setRotate__23dDlst_StarterScrnDraw_cFP18fopMsgM_pane_classf */
void dDlst_StarterScrnDraw_c::setRotate(fopMsgM_pane_class*, f32) {
    /* Nonmatching */
}

/* 80206E44-80206EDC       .text draw__23dDlst_StarterScrnDraw_cFv */
void dDlst_StarterScrnDraw_c::draw() {
    /* Nonmatching */
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
