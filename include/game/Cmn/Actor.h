#include <types.h>

namespace Cmn {
class Actor {
    // Size: 0x28
  public:
    // vtable is at 0x1012265C
    virtual ~Actor() {}
    virtual void vf0(); // Deleted
    virtual bool checkDerivedRuntimeTypeInfo(char* a2);
    virtual void vf2();
    virtual void load();
    virtual void vf4();
    virtual void onActivate();
    virtual void vf6();
    virtual void firstCalc();
    virtual void vf8();
    virtual void secondCalc();
    virtual void vf10();
    virtual void thirdCalc();
    virtual void fourthCalc();
    virtual void fifthCalc();
    virtual void vf14();
    virtual void vf15();
    virtual const char* getClassName();
    virtual int maybeMtx1(); // returns either this->_08 + 52 if _08 == 0 or 0, maybe Mtx related based on Splatoon 2 names and functionality?
    virtual int maybeMtx2(); // returns either this->_08 + 100 if _08 == 0 or 0, maybe Mtx related based on Splatoon 2 names functionality?
    virtual int vf19();      // returns firstCalc if this->_subobject2 & 1 == 0
    virtual int vf20();      // returns vf8 if this->_subobject2 >> 1 & 1 == 0
    virtual int vf21();      // returns secondCalc if this->_subobject2 >> 2 & 1 == 0
    virtual int vf22();      // sub_285B100, calls vf10 if this->_subobject2 >> 3 & 1 == 0
    virtual int vf23();      // calls thirdCalc if this->_subobject2 >> 4 & 1 == 0
    virtual int vf24();      // calls fourthCalc if this->_subobject2 >> 5 & 1 == 0
    virtual int vf25();      // calls fifthCalc if this->_subobject2 >> 6 & 1 == 0
    virtual int vf26();      // returns load()
    virtual int vf27();      // returns vf4
    virtual int vf28();      // returns onActivate
    virtual int vf29();      // returns vf6
    virtual int vf30();      // returns vf14
    virtual int vf31();      // returns vf15
    virtual void vf32();     // Unimpd
    virtual int vf33();      // if this->_1C == 3, set 1C to 2 and return vf32

    // void * vtable;
    void* subobject1;
    u32 _08;
    u32* subobject2;
    u32 _10;
    u32 _14;
    u32 _18;
    u32 _1C;
    u32 _20;
    u8 pad[4];

    Actor();
};
static_assert(sizeof(Actor) == 0x28, "Cmn::Actor size mismatch");
} // namespace Cmn