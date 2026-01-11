#ifndef D_MINIGAME_STARTER_H
#define D_MINIGAME_STARTER_H

#include "d/d_drawlist.h"
#include "dolphin/types.h"
#include "f_op/f_op_msg.h"

class JKRArchive;
struct fopMsgM_pane_class;

class dDlst_StarterScrnDraw_c : public dDlst_base_c {
public:
    void acc(s16, s16, s16) {}
    
    void setScreen(const char*, JKRArchive*);
    void anime1(int);
    void anime2();
    void scaleAnime(f32);
    void setRotate(fopMsgM_pane_class*, f32);
    void draw();
public:
    u8 padding[0x314];
};

class dMinigame_Starter_c : public msg_class {
public:
    void countStart() { if (!field_0x111) field_0x111 = true; }
    
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
    /* 0x110 */ u8 field_0x110[0x111 - 0x110];
    /* 0x111 */ bool field_0x111;
    /* 0x112 */ u8 field_0x112[0x114 - 0x112];
};  // Size: 0x114

#endif /* D_MINIGAME_STARTER_H */
