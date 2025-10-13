#include <types.h>
#include "Cmn/Actor.h"

namespace Game {

class GambitActor : public Cmn::Actor {

    struct GambitActorSubStructThing {
        // Game::GambitActor *owner;
        u8 unk3;
        u8 unk4;
        u16 pad;
    };

    // Size: 0x50
  public:
    // vtable is at 0x100000D8
    void vf0(); // Deleted(?)
    bool checkDerivedRuntimeTypeInfo(char* a2);
    void vf2();
    void load();
    void vf4();
    void onActivate();
    void vf6();
    void firstCalc();
    void vf8();
    void secondCalc();
    void vf10();
    void thirdCalc();
    void fourthCalc();
    void fifthCalc();
    void vf14();
    void vf15();
    const char* getClassName() override;
    int maybeMtx1() override;   // returns either this->_08 + 52 if _08 == 0 or 0, maybe Mtx related based on Splatoon 2 names and functionality?
    int maybeMtx2() override;   // returns either this->_08 + 100 if _08 == 0 or 0, maybe Mtx related based on Splatoon 2 names functionality?
    int vf19() override;        // calls maybeMtx1 if this->_subobject2 & 1 == 0 then returns checkDerivedRTTI
    int vf20() override;        // returns checkDerivedRTTI if this->_subobject2 >> 1 & 1 == 0
    int vf21() override;        // returns firstCalc if this->_subobject2 >> 2 & 1 == 0
    int vf22();                 // returns secondCalc if this->_subobject2 >> 3 & 1 == 0
    int vf23();                 // calls thirdCalc if this->_subobject2 >> 4 & 1 == 0
    int vf24();                 // calls fourthCalc if this->_subobject2 >> 5 & 1 == 0
    int vf25();                 // calls fifthCalc if this->_   subobject2 >> 6 & 1 == 0
    int vf26();                 // ActorLoadChildHeap related
    int vf27();                 // returns vf4
    int vf28();                 // Calls onActivate, calls some virt function in _30, sets _38 to 0
    int vf29();                 // Calls vf6, then unk_200055C
    int vf30();                 // Calls 2884A48 with this_30 and 1, 205BE7C with _30, vf10, vf14, and sets some struct flag to 1
    int vf31();                 // Calls vf15, does some other checks idk
    void vf32();                // More virtfunc calls to list later
    int vf33();                 // If _1C != 3, call vf32 then set _1C to 2
    void vf34();                // Deleted
    virtual const char* vf35(); // Returns getClassName
    virtual int vf36();         // Returns vf35
    virtual int vf37();         // ^
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual int vf42();          // Returns 1
    virtual int vf43();          // Returns 4
    virtual int vf44(int unk);   // Calls unk_2884178(a1->_30, a2, a1->_08, 0), something with skeletal animations?
    virtual void vf45(int* unk); // Comapres something in a struct unk is pointing to
    virtual void vf46();
    virtual void vf47();
    virtual void vf48(); // Calls vf51
    virtual void vf49(); // Calls vf52
    virtual void vf50(); // Calls vf53
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56(); // Doc later
    virtual int vf57();  // Returns 1
    virtual int vf58();  // Returns 0

    u32 _28;
    s32 _2C;
    u32 _30;
    u32 _34;
    u32 _38;
    GambitActorSubStructThing unkThing;
    u8 _40;
    u8 _41;
    u16 _42;
    u8 _44;
    u8 pad[11];

    GambitActor();
};
static_assert(sizeof(GambitActor) == 0x50, "Game::GambitActor size mismatch");
} // namespace Game