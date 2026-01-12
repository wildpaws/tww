#ifndef D_MINIGAME_STARTER_H
#define D_MINIGAME_STARTER_H

#include "d/d_drawlist.h"
#include "dolphin/types.h"
#include "f_op/f_op_msg.h"
#include "f_op/f_op_msg_mng.h"

class J2DScreen;
class JKRArchive;
struct fopMsgM_pane_class;

class dDlst_StarterScrnDraw_c : public dDlst_base_c {
public:
    f32 acc(s16 param_0, s16 param_1, s16 param_2) {
        return ((f32)(param_1 - param_2) * (f32)(param_1 - param_2)) / ((f32)(param_0 - param_2) * (f32)(param_0 - param_2));
    }
    
    void setScreen(const char*, JKRArchive*);
    bool anime1(int);
    void anime2();
    void scaleAnime(f32);
    void setRotate(fopMsgM_pane_class*, f32);
    virtual void draw();
public:
    /* 0x004 */ J2DScreen* field_0x004;
    /* 0x008 */ fopMsgM_pane_class field_0x008[3];
    /* 0x0B0 */ fopMsgM_pane_class field_0x0B0;
    /* 0x0E8 */ fopMsgM_pane_class field_0x0E8[3];
    /* 0x190 */ fopMsgM_pane_class field_0x190;
    /* 0x1C8 */ fopMsgM_pane_class field_0x1C8[3];
    /* 0x270 */ fopMsgM_pane_class field_0x270[3];
};  // Size: 0x318

class dMinigame_Starter_c : public msg_class {
public:
    void countStart() { if (field_0x111 == 0) field_0x111 = 1; }
    s32 fake(s32 param_1, s32 param_2) { return param_1 + param_2;  }

    cPhs_State _create();
    BOOL _execute();
    BOOL _draw();
    BOOL _delete();
    BOOL startCheck();
    BOOL deleteCheck();
public:
    /* 0x0FC */ dDlst_StarterScrnDraw_c* field_0x0FC;
    /* 0x100 */ request_of_phase_process_class field_0x100;
    /* 0x108 */ JKRSolidHeap* field_0x108;
    /* 0x10C */ s16 field_0x10C;
    /* 0x10E */ s16 field_0x10E;
    /* 0x110 */ u8 mUnused;
    /* 0x111 */ u8 field_0x111;
    /* 0x112 */ /* 2 bytes of alignment padding*/
};  // Size: 0x114

#endif /* D_MINIGAME_STARTER_H */
