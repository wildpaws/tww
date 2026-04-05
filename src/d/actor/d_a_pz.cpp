/**
 * d_a_pz.cpp
 * NPC - Princess Zelda
 */

#include "d/dolzel_rel.h" // IWYU pragma: keep
#include "d/actor/d_a_pz.h"
#include "d/actor/d_a_gnd.h"
#include "d/actor/d_a_item.h"
#include "d/d_material.h"
#include "d/d_procname.h"
#include "d/d_priority.h"
#include "d/d_cc_d.h"
#include "d/d_s_play.h"
#include "d/d_snap.h"

const u32 daPz_c::m_heapsize = 42816;
const char daPz_c::m_arc_name[] = "PZ";
const dCcD_SrcCyl daPz_c::m_cyl_src = {
    // dCcD_SrcGObjInf
    {
        /* Flags             */ 0,
        /* SrcObjAt  Type    */ 0,
        /* SrcObjAt  Atp     */ 0,
        /* SrcObjAt  SPrm    */ 0,
        /* SrcObjTg  Type    */ AT_TYPE_ALL & ~AT_TYPE_WATER & ~AT_TYPE_UNK20000 & ~AT_TYPE_WIND & ~AT_TYPE_UNK400000,
        /* SrcObjTg  SPrm    */ cCcD_TgSPrm_Set_e | cCcD_TgSPrm_IsOther_e,
        /* SrcObjCo  SPrm    */ cCcD_CoSPrm_Set_e | cCcD_CoSPrm_VsGrpAll_e,
        /* SrcGObjAt Se      */ 0,
        /* SrcGObjAt HitMark */ dCcG_AtHitMark_None_e,
        /* SrcGObjAt Spl     */ dCcG_At_Spl_UNK0,
        /* SrcGObjAt Mtrl    */ 0,
        /* SrcGObjAt SPrm    */ 0,
        /* SrcGObjTg Se      */ dCcG_SE_UNK23,
        /* SrcGObjTg HitMark */ 0,
        /* SrcGObjTg Spl     */ dCcG_Tg_Spl_UNK0,
        /* SrcGObjTg Mtrl    */ 0,
        /* SrcGObjTg SPrm    */ dCcG_TgSPrm_NoConHit_e | dCcG_TgSPrm_NoHitMark_e,
        /* SrcGObjCo SPrm    */ 0,
    },
    // cM3dGCylS
    {{
        /* Center */ {0.0f, 0.0f, 0.0f},
        /* Radius */ 0.0f,
        /* Height */ 0.0f,
    }},
};

static daPz_HIO_c l_HIO;

/* 000000EC-00000310       .text __ct__10daPz_HIO_cFv */
daPz_HIO_c::daPz_HIO_c() {
    /* Apparent match */
    field_0x02C = 0;
    field_0x02D = 1;
    field_0x032 = 0;
    field_0x033 = 0;

    for (int i = 0; i < 10; i++) {
        field_0x034[i] = 0;
    }

    field_0x004.m04 = -20.0;
    field_0x004.mMaxHeadX = 0x1FFE;
    field_0x004.mMaxHeadY = 10000;
    field_0x004.mMaxBackboneX = 7000;
    field_0x004.mMaxBackboneY = 13000;
    field_0x004.mMinHeadX = -0x9C4;
    field_0x004.mMinHeadY = -10000;
    field_0x004.mMinBackboneX = -7000;
    field_0x004.mMinBackboneY = -13000;
    field_0x004.mMaxTurnStep = 0x1000;
    field_0x004.mMaxHeadTurnVel = 0x800;
    field_0x004.mAttnYOffset = 50.0;
    field_0x004.mMaxAttnAngleY = 13000;
    field_0x004.m22 = 0;
    field_0x004.mMaxAttnDistXZ = 400.0;

    field_0x040 = 60.0;
    field_0x02F = 0;
    field_0x054 = 0x2000;
    field_0x058 = 200.0;
    field_0x044 = 1.2;
    field_0x04C = 0.9;
    field_0x048 = 2.0;
    field_0x050 = 10.0;
    field_0x031 = 0;
    field_0x05C = 100.0;
    field_0x068 = 0.0;
    field_0x074 = 100.0;
    field_0x080 = 0x1E;
    field_0x086 = 300;
    field_0x08C = 0;
    field_0x092 = 0x1E;
    field_0x098 = 0;
    field_0x0A0 = 1000.0;
    field_0x0F8 = 0x3c;
    field_0x100[0] = 3000.0;
    field_0x064 = 100.0;
    field_0x070 = 100.0;
    field_0x07C = 80.0;
    field_0x084 = 0x1E;
    field_0x08A = 100;
    field_0x090 = 100;
    field_0x096 = 0x1E;
    field_0x09C = 0x3C;
    field_0x0A8 = 1000.0;
    field_0x0FC = 600;
    field_0x100[2] = 800.0;
    field_0x0AC = 100.0;
    field_0x0E2 = 4;
    field_0x0E4 = 6;
    field_0x0E6 = 4;
    field_0x0E8 = 6;
    field_0x0B0 = -2.5;
    field_0x0B4 = 20.0;
    field_0x0B8 = 20.0;
    field_0x0BC = 20.0;
    field_0x0C0 = 20.0;
    field_0x0C4 = 4.0;
    field_0x0C8 = 15.0;
    field_0x0CC = 0xE;
    field_0x0D8 = 30.0;
    field_0x0DC = 0x28;
    field_0x0DE = 0x28;
    field_0x0E0 = 5;
    field_0x0D0 = 600.0;
    field_0x0EC = 800.0;
    field_0x0D4 = 15.0;
    field_0x0F0 = 2.0;
    field_0x0F4 = 1.0;
}

/* 00000310-00000340       .text stealItem_CB__FPv */
static BOOL stealItem_CB(void* actor) {
    if (actor != NULL) {
        daItem_c* item = (daItem_c *) actor;
        item->scale.setall(1.0f);
        item->setFlag(daItem_c::FLAG_HOOK);
    }
    return TRUE;
}

/* 00000340-0000038C       .text nodeHeadControl_CB__FP7J3DNodei */
static BOOL nodeHeadControl_CB(J3DNode* i_nodeP, int i_calcTiming) {
    if (i_calcTiming == J3DNodeCBCalcTiming_In) {
        J3DModel* model_p = j3dSys.getModel();
        if (model_p->getUserArea() != NULL) {
            daPz_c* this_p = (daPz_c *) model_p->getUserArea();
            this_p->_nodeHeadControl(i_nodeP, model_p);
        }
    }
    return TRUE;
}

/* 0000038C-000004FC       .text _nodeHeadControl__6daPz_cFP7J3DNodeP8J3DModel */
void daPz_c::_nodeHeadControl(J3DNode* i_nodeP, J3DModel* i_modelP) {
    /* Nonmatching */
    u16 jnt_no = ((J3DJoint *)i_nodeP)->getJntNo();
    
    mDoMtx_stack_c::copy(i_modelP->getAnmMtx(jnt_no));

    static cXyz l_offsetAttPos(0.0f, 0.0f, 0.0f);
    static cXyz l_offsetEyePos(24.0f, -16.0f, 0.0f);

    mDoMtx_stack_c::multVec(&l_offsetAttPos, &m08B8);
    mDoMtx_stack_c::YrotM(-m_jnt.getHead_y());
    mDoMtx_stack_c::ZrotM(-m_jnt.getHead_x());
    mDoMtx_stack_c::multVec(&l_offsetEyePos, &m08DC);
    mDoMtx_stack_c::multVecZero(&m072C);

    cMtx_copy(mDoMtx_stack_c::get(), J3DSys::mCurrentMtx);
    i_modelP->setAnmMtx(jnt_no, mDoMtx_stack_c::get());
}

/* 00000538-00000584       .text nodeWaistControl_CB__FP7J3DNodei */
static BOOL nodeWaistControl_CB(J3DNode* i_nodeP, int i_calcTiming) {
    if (i_calcTiming == J3DNodeCBCalcTiming_In) {
        J3DModel* model_p = j3dSys.getModel();
        if (model_p->getUserArea() != NULL) {
            daPz_c* this_p = (daPz_c *) model_p->getUserArea();
            this_p->_nodeWaistControl(i_nodeP, model_p);
        }
    }
    return TRUE;
}

/* 00000584-00000710       .text _nodeWaistControl__6daPz_cFP7J3DNodeP8J3DModel */
void daPz_c::_nodeWaistControl(J3DNode* i_nodeP, J3DModel* i_modelP) {
    /* Apparent match */
    static s16 tmp_angle;
    u16 jnt_no = ((J3DJoint *)i_nodeP)->getJntNo();
    tmp_angle += 0x1000;

    mDoMtx_stack_c::copy(i_modelP->getAnmMtx(jnt_no));

    if ((s8)mAnmType == 4 || (s8)mAnmType == 5 || (s8)mAnmType == 6) {
        mDoMtx_stack_c::ZrotM(0xDAC);
        mDoMtx_stack_c::YrotM(0x5DC);
    }

    if (REG12_S(6) != 0) {
        mDoMtx_stack_c::XrotM(tmp_angle);
    } else {
        mDoMtx_stack_c::XrotM(+m_jnt.getBackbone_y());
        mDoMtx_stack_c::ZrotM(-m_jnt.getBackbone_x());
    }

    if ((s8)mAnmType == 4 || (s8)mAnmType == 5 || (s8)mAnmType == 6) {
        mDoMtx_stack_c::YrotM(-0x5DC);
        mDoMtx_stack_c::ZrotM(-0xDAC);
    }

    cMtx_copy(mDoMtx_stack_c::get(), m0F08);
    mDoMtx_stack_c::multVecZero(&m0F38);
    
    cMtx_copy(mDoMtx_stack_c::get(), J3DSys::mCurrentMtx);
    i_modelP->setAnmMtx(jnt_no, mDoMtx_stack_c::get());
}

/* 00000710-0000075C       .text nodeWaist2Control_CB__FP7J3DNodei */
static BOOL nodeWaist2Control_CB(J3DNode* i_nodeP, int i_calcTiming) {
    if (i_calcTiming == J3DNodeCBCalcTiming_In) {
        J3DModel* model_p = j3dSys.getModel();
        if (model_p->getUserArea() != NULL) {
            daPz_c* this_p = (daPz_c *) model_p->getUserArea();
            this_p->_nodeWaist2Control(i_nodeP, model_p);
        }
    }
    return TRUE;
}

/* 0000075C-000007F4       .text _nodeWaist2Control__6daPz_cFP7J3DNodeP8J3DModel */
void daPz_c::_nodeWaist2Control(J3DNode* i_nodeP, J3DModel* i_modelP) {
    u16 jnt_no = ((J3DJoint *)i_nodeP)->getJntNo();
    
    mDoMtx_stack_c::copy(i_modelP->getAnmMtx(jnt_no));
    mDoMtx_stack_c::YrotM(m0F7A);
    mDoMtx_stack_c::ZrotM(m0F78);
    
    cMtx_copy(mDoMtx_stack_c::get(), J3DSys::mCurrentMtx);
    i_modelP->setAnmMtx(jnt_no, mDoMtx_stack_c::get());
}

/* 000007F4-00000840       .text nodeSkirtControl_CB__FP7J3DNodei */
static BOOL nodeSkirtControl_CB(J3DNode* i_nodeP, int i_calcTiming) {
    if (i_calcTiming == J3DNodeCBCalcTiming_In) {
        J3DModel* model_p = j3dSys.getModel();
        if (model_p->getUserArea() != NULL) {
            daPz_c* this_p = (daPz_c *) model_p->getUserArea();
            this_p->_nodeSkirtControl(i_nodeP, model_p);
        }
    }
    return TRUE;
}

/* 00000840-00000920       .text _nodeSkirtControl__6daPz_cFP7J3DNodeP8J3DModel */
void daPz_c::_nodeSkirtControl(J3DNode* i_nodeP, J3DModel* i_modelP) {
    u16 jnt_no = ((J3DJoint *)i_nodeP)->getJntNo();
    
    mDoMtx_stack_c::copy(i_modelP->getAnmMtx(jnt_no));
    s16 temp = m0F78 > m0F7A ? m0F7A : m0F78;
    mDoMtx_stack_c::XrotM(REG12_S(2));
    mDoMtx_stack_c::YrotM(REG12_S(3));
    mDoMtx_stack_c::ZrotM(-(temp + REG12_S(4)));
    
    cMtx_copy(mDoMtx_stack_c::get(), J3DSys::mCurrentMtx);
    i_modelP->setAnmMtx(jnt_no, mDoMtx_stack_c::get());
}

/* 00000920-00000940       .text createHeap_CB__FP10fopAc_ac_c */
static BOOL createHeap_CB(fopAc_ac_c* i_this) {
    return ((daPz_c *)i_this)->_createHeap();
}

/* 00000940-00000D54       .text bodyCreateHeap__6daPz_cFv */
BOOL daPz_c::bodyCreateHeap() {
    /* Apparent match */
    J3DModelData* modelData = static_cast<J3DModelData *>(dComIfG_getObjectRes(m_arc_name, 0x18));
    JUT_ASSERT(0x23E, modelData != NULL);

    for (u16 i = 0; i < modelData->getMaterialNum(); i++) {
        J3DMaterial* material_p = modelData->getMaterialNodePointer(i); 
        material_p->setMaterialAnm(new daPz_matAnm_c());
    }

    mpMorf = new mDoExt_McaMorf(
        modelData, 
        NULL, NULL, NULL, 
        J3DFrameCtrl::EMode_NULL, 1.0f, 
        0, -1, true, NULL, 
        0x80000, 0x11020222
    );

    if (!mpMorf || !mpMorf->getModel()) {
        return FALSE;
    }

    mpMorf->getModel()->setUserArea((u32) this);

    if (!mInvisibleModel.create(mpMorf->getModel())) {
        return FALSE;
    }

    m_jnt.setHeadJntNum(4);
    modelData->getJointTree().getJointNodePointer(4)->setCallBack(nodeHeadControl_CB);
    m_jnt.setBackboneJntNum(1);
    modelData->getJointTree().getJointNodePointer(1)->setCallBack(nodeWaistControl_CB);
    modelData->getJointTree().getJointNodePointer(21)->setCallBack(nodeWaist2Control_CB);
    modelData->getJointTree().getJointNodePointer(25)->setCallBack(nodeSkirtControl_CB);

    J3DAnmTexPattern* btp = static_cast<J3DAnmTexPattern *>(dComIfG_getObjectRes(m_arc_name, 0x27));
    JUT_ASSERT(0x277, btp != NULL);

    if (!mBtpAnm.init(modelData, btp, TRUE, 0)) {
        return FALSE;
    }

    J3DAnmTextureSRTKey* btk = static_cast<J3DAnmTextureSRTKey *>(dComIfG_getObjectRes(m_arc_name, 0x1F));
    JUT_ASSERT(0x27D, btk != NULL);

    if (!mBtkAnm.init(modelData, btk, TRUE, 0)) {
        return FALSE;
    }

    u16 update_mat_num = mBtkAnm.getBtkAnm()->getUpdateMaterialNum();
    for (u16 i = 0; i < update_mat_num; i++) {
        J3DMaterialAnm* material_p = modelData
            ->getMaterialNodePointer(mBtkAnm.getBtkAnm()->getUpdateMaterialID(i))
            ->getMaterialAnm();
        m08A8[i] = material_p;
    }

    J3DAnmTevRegKey* brk = static_cast<J3DAnmTevRegKey *>(dComIfG_getObjectRes(m_arc_name, 0x1B));
    JUT_ASSERT(0x28E, brk != NULL);

    if (!mBrkAnm.init(modelData, brk, TRUE, 2)) {
        return FALSE;
    }

    return TRUE;
}

/* 00000D54-00000E74       .text bowCreateHeap__6daPz_cFv */
BOOL daPz_c::bowCreateHeap() {
    /* Apparent match */
    J3DModelData* modelData = static_cast<J3DModelData *>(dComIfG_getObjectRes(m_arc_name, 0x17));
    JUT_ASSERT(0x29F, modelData != NULL);

    mpBowMcaMorf = new mDoExt_McaMorf(
        modelData,
        NULL, NULL, NULL, 
        J3DFrameCtrl::EMode_NULL, 1.0f, 
        0, -1, true, NULL, 
        0x80000, 0x11000022
    );

    if (!mpBowMcaMorf || !mpBowMcaMorf->getModel()) {
        return FALSE;
    }

    mpBowMcaMorf->getModel()->setUserArea((u32) this);

    return TRUE;
}

/* 00000E74-00000EC0       .text _createHeap__6daPz_cFv */
BOOL daPz_c::_createHeap() {
    // lol
    return !bodyCreateHeap() ? FALSE : (bowCreateHeap() ? TRUE : FALSE);
}

/* 00000EC0-00000F20       .text __ct__13daPz_matAnm_cFv */
daPz_matAnm_c::daPz_matAnm_c() {
    /* Apparent match */
    field_0x7C = 0;
    field_0x6C.x = 0.0f;
    field_0x6C.y = 0.0f;
}

/* 00000F20-00000FB4       .text calc__13daPz_matAnm_cCFP11J3DMaterial */
void daPz_matAnm_c::calc(J3DMaterial* i_matP) const {
    J3DMaterialAnm::calc(i_matP);
    for (u32 i = 0; i < 8; i++) {
        if (getTexMtxAnm(i)) {
            J3DTexMtx* tex_mtx = i_matP->getTexMtx(i);
            if (field_0x7C != 0) {
                tex_mtx->getTextureSRT().mTranslationX = field_0x6C.x;
                tex_mtx->getTextureSRT().mTranslationY = field_0x6C.y;
            }
        }
    }
}

/* 00000FB4-00001038       .text getGndPos__6daPz_cFv */
void daPz_c::getGndPos() {
    /* Nonmatching */
}

/* 00001038-0000114C       .text checkEyeArea__6daPz_cFR4cXyz */
bool daPz_c::checkEyeArea(cXyz&) {
    /* Nonmatching */
}

/* 0000114C-00001194       .text getMsg__6daPz_cFv */
u32 daPz_c::getMsg() {
    u32 msg_no = 0x3562;
    if (m08B0 == 0) {
        msg_no = 0x3562;
    } else if (m08B0 == 2) {
        if (m0F65 == 0) {
            m0F65 = 1;
            msg_no = 0x3563;
        } else {
            msg_no = 0x3565;
        }
    }
    return msg_no;
}

/* 00001194-00001208       .text next_msgStatus__6daPz_cFPUl */
u16 daPz_c::next_msgStatus(unsigned long*) {
    /* Nonmatching */
}

/* 00001208-00001288       .text anmAtr__6daPz_cFUs */
void daPz_c::anmAtr(u16 i_msgStatus) {
    /* Nonmatching */
}

/* 00001288-000012D4       .text eventOrder__6daPz_cFv */
void daPz_c::eventOrder() {
    /* Nonmatching */
}

/* 000012D4-00001338       .text checkOrder__6daPz_cFv */
void daPz_c::checkOrder() {
    /* Nonmatching */
}

/* 00001338-0000151C       .text setFallSplash__6daPz_cFv */
void daPz_c::setFallSplash() {
    /* Nonmatching */
}

/* 0000151C-000015F4       .text setHeadSplash__6daPz_cFv */
void daPz_c::setHeadSplash() {
    /* Nonmatching */
}

/* 000015F4-00001704       .text setRipple__6daPz_cFv */
void daPz_c::setRipple() {
    /* Nonmatching */
}

/* 00001704-0000175C       .text setJntStatus__6daPz_cFv */
void daPz_c::setJntStatus() {
    /* Nonmatching */
}

/* 0000175C-00001954       .text demo__6daPz_cFv */
bool daPz_c::demo() {
    /* Nonmatching */
}

/* 00001954-00001EEC       .text checkTgHit__6daPz_cFv */
void daPz_c::checkTgHit() {
    /* Nonmatching */
}

/* 00001EEC-00001F10       .text getArg__6daPz_cFv */
void daPz_c::getArg() {
    /* Nonmatching */
}

/* 00001F10-000020B8       .text setAttention__6daPz_cFv */
void daPz_c::setAttention() {
    /* Nonmatching */
}

/* 000020B8-00002114       .text setBowAnm__6daPz_cFScb */
void daPz_c::setBowAnm(signed char, bool) {
    /* Nonmatching */
}

/* 00002114-00002184       .text setBowString__6daPz_cFb */
void daPz_c::setBowString(bool) {
    /* Nonmatching */
}

/* 00002184-0000246C       .text setAnm__6daPz_cFScbi */
void daPz_c::setAnm(signed char, bool, int) {
    /* Nonmatching */
}

/* 0000246C-00002684       .text setAnmRunSpeed__6daPz_cFv */
void daPz_c::setAnmRunSpeed() {
    /* Nonmatching */
}

/* 00002684-0000274C       .text setEyeBtp__6daPz_cFi */
void daPz_c::setEyeBtp(int) {
    /* Nonmatching */
}

/* 0000274C-00002810       .text setEyeBtk__6daPz_cFi */
void daPz_c::setEyeBtk(int) {
    /* Nonmatching */
}

/* 00002810-00002888       .text setEyeAnm__6daPz_cFSc */
void daPz_c::setEyeAnm(signed char) {
    /* Nonmatching */
}

/* 00002888-00002AE0       .text ctrlEye__6daPz_cFv */
void daPz_c::ctrlEye() {
    /* Nonmatching */
}

/* 00002AE0-00002D38       .text playEyeAnm__6daPz_cFv */
void daPz_c::playEyeAnm() {
    /* Nonmatching */
}

/* 00002D38-00002DC8       .text setMtx__6daPz_cFv */
void daPz_c::setMtx() {
    /* Nonmatching */
}

/* 00002DC8-00002E2C       .text modeWaitInit__6daPz_cFv */
void daPz_c::modeWaitInit() {
    /* Nonmatching */
}

/* 00002E2C-00002FE8       .text modeWait__6daPz_cFv */
void daPz_c::modeWait() {
    /* Nonmatching */
}

/* 00002FE8-000031E8       .text modeMoveInit__6daPz_cFv */
void daPz_c::modeMoveInit() {
    /* Nonmatching */
}

/* 000031E8-0000395C       .text modeMove__6daPz_cFv */
void daPz_c::modeMove() {
    /* Nonmatching */
}

/* 0000395C-000039C0       .text modeAttackWaitInit__6daPz_cFv */
void daPz_c::modeAttackWaitInit() {
    /* Nonmatching */
}

/* 000039C0-00003D88       .text modeAttackWait__6daPz_cFv */
void daPz_c::modeAttackWait() {
    /* Nonmatching */
}

/* 00003D88-00003F14       .text modeAttackInit__6daPz_cFv */
void daPz_c::modeAttackInit() {
    /* Nonmatching */
}

/* 00003F14-0000445C       .text modeAttack__6daPz_cFv */
void daPz_c::modeAttack() {
    /* Nonmatching */
}

/* 0000445C-000044B4       .text modeDefendInit__6daPz_cFv */
void daPz_c::modeDefendInit() {
    /* Nonmatching */
}

/* 000044B4-00004630       .text modeDefend__6daPz_cFv */
void daPz_c::modeDefend() {
    /* Nonmatching */
}

/* 00004630-0000470C       .text modeDownInit__6daPz_cFv */
void daPz_c::modeDownInit() {
    /* Nonmatching */
}

/* 0000470C-00004C20       .text modeDown__6daPz_cFv */
void daPz_c::modeDown() {
    /* Nonmatching */
}

/* 00004C20-00004C78       .text modeAfraidInit__6daPz_cFv */
void daPz_c::modeAfraidInit() {
    /* Nonmatching */
}

/* 00004C78-00004E8C       .text modeAfraid__6daPz_cFv */
void daPz_c::modeAfraid() {
    /* Nonmatching */
}

/* 00004E8C-00004F08       .text modeSideStepInit__6daPz_cFv */
void daPz_c::modeSideStepInit() {
    /* Nonmatching */
}

/* 00004F08-00005098       .text modeSideStep__6daPz_cFv */
void daPz_c::modeSideStep() {
    /* Nonmatching */
}

/* 00005098-00005114       .text modeBackStepInit__6daPz_cFv */
void daPz_c::modeBackStepInit() {
    /* Nonmatching */
}

/* 00005114-0000527C       .text modeBackStep__6daPz_cFv */
void daPz_c::modeBackStep() {
    /* Nonmatching */
}

/* 0000527C-00005304       .text modeTalkInit__6daPz_cFv */
void daPz_c::modeTalkInit() {
    /* Nonmatching */
}

/* 00005304-0000539C       .text modeTalk__6daPz_cFv */
void daPz_c::modeTalk() {
    /* Nonmatching */
}

/* 0000539C-0000549C       .text modeFollowInit__6daPz_cFv */
void daPz_c::modeFollowInit() {
    /* Nonmatching */
}

/* 0000549C-000059B8       .text modeFollow__6daPz_cFv */
void daPz_c::modeFollow() {
    /* Nonmatching */
}

/* 000059B8-00005C58       .text modeProc__6daPz_cFQ26daPz_c6Proc_ei */
void daPz_c::modeProc(daPz_c::Proc_e i_procType, int i_modeNo) {
    /* Nonmatching - .data offsets */
    static ModeEntry mode_tbl[] = {
        { &daPz_c::modeWaitInit,       &daPz_c::modeWait,       "WAIT"       },
        { &daPz_c::modeMoveInit,       &daPz_c::modeMove,       "MOVE"       },
        { &daPz_c::modeAttackWaitInit, &daPz_c::modeAttackWait, "ATTACKWAIT" },
        { &daPz_c::modeAttackInit,     &daPz_c::modeAttack,     "ATTACK"     },
        { &daPz_c::modeDefendInit,     &daPz_c::modeDefend,     "DEFEND"     },
        { &daPz_c::modeDownInit,       &daPz_c::modeDown,       "DOWN"       },
        { &daPz_c::modeAfraidInit,     &daPz_c::modeAfraid,     "AFRAID"     },
        { &daPz_c::modeSideStepInit,   &daPz_c::modeSideStep,   "SIDE_STEP"  },
        { &daPz_c::modeBackStepInit,   &daPz_c::modeBackStep,   "BACK_STEP"  },
        { &daPz_c::modeTalkInit,       &daPz_c::modeTalk,       "TALK"       },
        { &daPz_c::modeFollowInit,     &daPz_c::modeFollow,     "FOLLOW"     }
    };

    if (i_procType == PROC_INIT_e) {
        mMode = i_modeNo;
        (this->*mode_tbl[mMode].mInitFunc)();
    } else if (i_procType == PROC_EXEC_e) {
        (this->*mode_tbl[mMode].mUpdFunc)();
    }
}

/* 00005C58-000060D8       .text _execute__6daPz_cFv */
bool daPz_c::_execute() {
    /* Apparent match */
    if (l_HIO.field_0x033 != 0) {
        modeProcInit(MODE_WAIT);
        fopAc_ac_c* link_p = dComIfGp_getLinkPlayer();
        current.pos = link_p->current.pos;
        
        current.pos.y += 50.0f;
        current.pos.x -= cM_ssin(link_p->shape_angle.y) * 200.0f;
        current.pos.z -= cM_scos(link_p->shape_angle.y) * 200.0f;
    }

    setFallSplash();
    getGndPos();
    
    mbEyesFollowGanondorf = 0;
    if(mbHasGanondorf != 0) {
        mbEyesFollowGanondorf = checkEyeArea(mGanondorfPosCurrent);
    }

    gravity = l_HIO.field_0x0B0;
    if (mMode != MODE_AFRAID && mMode != MODE_DOWN && m073F != 0) {
        modeProcInit(MODE_AFRAID);
    }
    
    setRipple();

    if (mMode != MODE_DOWN && m08B0 == 1) {
        modeProcInit(MODE_DOWN);
    }

    setJntStatus();

    if (demo()) {
        mBtkAnm.play();
        mBrkAnm.play();
        setMtx();
        g_env_light.settingTevStruct(TEV_TYPE_ACTOR, &current.pos, &tevStr);
        return true;
    }

    current.angle = shape_angle;
    mpMorf->calc();
    enemy_fire(&mEnemyFire);
    BOOL ice_result = enemy_ice(&mEventIce);

    if (ice_result) {
        mpMorf->getModel()->setBaseTRMtx(mDoMtx_stack_c::get());
        return true;
    }

    // TODO: fix this cast
    if ((s32)mAnmType == 9) {
        setHeadSplash();
    }

    if (mArg == 0 && (m08B0 == 0 || m08B0 == 2) && m0F80 == 0) {
        if (mMode != MODE_ATTACKWAIT && mMode != MODE_ATTACK && mMode != MODE_DOWN && mMode != MODE_TALK) {
            if (cLib_calcTimer(&m0F7C) == 0) {
                fopAc_ac_c* actor_proc;
                if (fopAcM_SearchByName(PROC_GND, &actor_proc) != 0) {
                    gnd_class* ganondorf_p = (gnd_class *) actor_proc;
                    if (
                        fopAcM_searchActorDistanceXZ(this, dComIfGp_getPlayer(0)) < l_HIO.field_0x100[m08B0] &&
                        ganondorf_p->mMoveType == 0 // move0
                    ) {
                        m0F82 = 1;
                        modeProcInit(MODE_TALK);
                    }
                }
            }
        }
    }

    checkOrder();
    modeProc(PROC_EXEC_e, MODE_NULL);
    eventOrder();
    setAttention();

    cLib_addCalc2(&speedF, m0924, 0.3f, 4.0f);

    s8 room_no = fopAcM_GetRoomNo(this);
    u32 snd_id = mObjAcch.ChkGroundHit() ? dComIfG_Bgsp()->GetMtrlSndId(mObjAcch.m_gnd) : 0;
    
    mpMorf->play(&eyePos, snd_id, dComIfGp_getReverb(room_no));
    mpBowMcaMorf->play(NULL, 0, 0);
    mBrkAnm.play();
    playEyeAnm();

    if (l_HIO.field_0x02F != 0) {
        setAnm(l_HIO.field_0x02F, false, 0xF);
    }

    fopAcM_posMoveF(this, NULL);
    mObjAcch.CrrPos(*dComIfG_Bgsp());

    if (!dComIfGp_event_runCheck()) {
        setCollision(30.0f, 130.0f);
    }

    setAnmRunSpeed();
    current.angle = shape_angle;
    setMtx();

    g_env_light.settingTevStruct(TEV_TYPE_ACTOR, &current.pos, &tevStr);

    return true;
}

/* 000060D8-00006154       .text bowDraw__6daPz_cFv */
void daPz_c::bowDraw() {
    /* Nonmatching */
}

/* 00006154-00006600       .text bodyDraw__6daPz_cFv */
void daPz_c::bodyDraw() {
    /* Nonmatching */
}

/* 00006600-000066D8       .text drawShadow__6daPz_cFv */
void daPz_c::drawShadow() {
    /* Nonmatching */
}

/* 000066D8-0000676C       .text _draw__6daPz_cFv */
bool daPz_c::_draw() {
    if (mEventIce.mFreezeTimer > 20) {
        dMat_control_c::mIce->entryDL(mpMorf, -1, &mInvisibleModel);
    } else {
        bodyDraw();
    }

    if (mDrawBowFlag != 0) {
        bowDraw();
    }

    drawShadow();
    dSnap_RegistFig(DSNAP_TYPE_UNK87, this, 1.0f, 1.0f, 1.0f);

    return true;
}

/* 0000676C-00006974       .text bodyCreateInit__6daPz_cFv */
void daPz_c::bodyCreateInit() {
    /* Nonmatching */
}

/* 00006974-00006BAC       .text createInit__6daPz_cFv */
void daPz_c::createInit() {
    max_health = 0x1E;
    health = max_health;
    stealItemLeft = 10;

    mEnemyFire.mpMcaMorf = mpMorf;
    mEnemyFire.mpActor = this;

    static u8 fire_j[10] = { 
         7,  2, 12, 13, 17, 
        18, 22, 23, 25, 26 
    };
    static f32 fire_sc[10] = { 
        2.0f, 2.0f, 1.0f, 1.0f, 1.0f, 
        1.0f, 1.0f, 1.0f, 1.0f, 1.0f 
    };

    for (int i = 0; i < ARRAY_SSIZE(mEnemyFire.mFlameTimers); i++) {
        mEnemyFire.mFlameJntIdxs[i] = fire_j[i];
        mEnemyFire.mParticleScale[i] = fire_sc[i];
    }

    mEventIce.mpActor = this;
    mEventIce.m00C = 1;
    mEventIce.mWallRadius = 50.0f;
    mEventIce.mCylHeight = 250.0f;
    
    m08B0 = 0;
    m0F7C = l_HIO.field_0x0F8;
    m0F80 = 0;
    bodyCreateInit();

    if (mArg == 0) {
        mDrawBowFlag = 1;
        modeProcInit(1);
        attention_info.distances[fopAc_Attn_TYPE_TALK_e] = 3;
        attention_info.distances[fopAc_Attn_TYPE_SPEAK_e] = 3;
        cLib_onBit<u32>(attention_info.flags, fopAc_Attn_ACTION_SPEAK_e);
        cLib_onBit<u32>(attention_info.flags, fopAc_Attn_LOCKON_TALK_e);
    } else {
        attention_info.flags = fopAc_Attn_LOCKON_TALK_e | fopAc_Attn_ACTION_SPEAK_e;
        modeProcInit(0);
    }

    m0920 = 1;
    fopAcM_SetMtx(this, mpMorf->getModel()->getBaseTRMtx());
    fopAcM_setCullSizeBox(this, -60.0f, -50.0f, -60.0f, 60.0f, 1800.0f, 60.0f);
    mAcchCir.SetWall(80.0f, 60.0f);
    mObjAcch.Set(
        fopAcM_GetPosition_p(this), 
        fopAcM_GetOldPosition_p(this), 
        this, 1, &mAcchCir, 
        fopAcM_GetSpeed_p(this)
    );
    mObjAcch.SetRoofNone();
    gravity = l_HIO.field_0x0B0;
    mStts.Init(255, 255, this);
    mCyl.Set(m_cyl_src);
    mCyl.SetStts(&mStts);
    setCollision(30.0f, 130.0f);
    dKy_tevstr_init(&mTevstr, fopAcM_GetHomeRoomNo(this), 255);
    g_env_light.settingTevStruct(TEV_TYPE_ACTOR, &current.pos, &tevStr);
}

/* 00006BAC-00006CB0       .text _create__6daPz_cFv */
cPhs_State daPz_c::_create() {
    cPhs_State state = dComIfG_resLoad(&mPhs, m_arc_name);

    fopAcM_SetupActor(this, daPz_c);

    if (state == cPhs_COMPLEATE_e) {
        getArg();
        if (
            mArg != 0 && 
            strcmp(dComIfGp_getStartStageName(), "kenroom") == 0 && 
            dComIfGs_isEventBit(dSv_event_flag_c::UNK_3520) == TRUE
        ) {
            return cPhs_ERROR_e;
        }

        if (!fopAcM_entrySolidHeap(this, createHeap_CB, m_heapsize)) {
            return cPhs_ERROR_e;
        }

        createInit();
    }

    return state;
}

/* 00007DA0-00007E20       .text _delete__6daPz_cFv */
bool daPz_c::_delete() {
    /* Nonmatching */
}

/* 00007E20-00007E40       .text daPzCreate__FPv */
static cPhs_State daPzCreate(void* i_this) {
    return ((daPz_c*)i_this)->_create();
}

/* 00007E40-00007E64       .text daPzDelete__FPv */
static BOOL daPzDelete(void* i_this) {
    return ((daPz_c*)i_this)->_delete();
}

/* 00007E64-00007E88       .text daPzExecute__FPv */
static BOOL daPzExecute(void* i_this) {
    return ((daPz_c*)i_this)->_execute();
}

/* 00007E88-00007EAC       .text daPzDraw__FPv */
static BOOL daPzDraw(void* i_this) {
    return ((daPz_c*)i_this)->_draw();
}

/* 00007EAC-00007EB4       .text daPzIsDelete__FPv */
static BOOL daPzIsDelete(void*) {
    return TRUE;
}

static actor_method_class daPzMethodTable = {
    (process_method_func)daPzCreate,
    (process_method_func)daPzDelete,
    (process_method_func)daPzExecute,
    (process_method_func)daPzIsDelete,
    (process_method_func)daPzDraw,
};

actor_process_profile_definition g_profile_PZ = {
    /* LayerID      */ fpcLy_CURRENT_e,
    /* ListID       */ 0x0007,
    /* ListPrio     */ fpcPi_CURRENT_e,
    /* ProcName     */ PROC_PZ,
    /* Proc SubMtd  */ &g_fpcLf_Method.base,
    /* Size         */ sizeof(daPz_c),
    /* SizeOther    */ 0,
    /* Parameters   */ 0,
    /* Leaf SubMtd  */ &g_fopAc_Method.base,
    /* Priority     */ PRIO_PZ,
    /* Actor SubMtd */ &daPzMethodTable,
    /* Status       */ 0x08 | fopAcStts_SHOWMAP_e | fopAcStts_CULL_e | fopAcStts_UNK40000_e,
    /* Group        */ fopAc_ACTOR_e,
    /* CullType     */ fopAc_CULLBOX_CUSTOM_e,
};
