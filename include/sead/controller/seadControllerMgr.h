#ifndef SEAD_CONTROLLER_MGR_H_
#define SEAD_CONTROLLER_MGR_H_

#include <container/seadOffsetList.h>
#include <controller/seadController.h>
#include <framework/seadCalculateTask.h>
#include <framework/seadTaskMgr.h>
#include <framework/seadTaskParameter.h>

namespace sead {

class ControlDevice;
class Controller;
class ControllerAddon;

class ControllerMgr : public CalculateTask
{
    SEAD_TASK_SINGLETON_DISPOSER(ControllerMgr)

private:
    class ConstructArg : public TaskConstructArg
    {
    public:
        ConstructArg()
            : TaskConstructArg()
            , mHeapArray()
        {
            heap_array = &mHeapArray;
        }

    private:
        HeapArray mHeapArray;
    };

public:
    struct Parameter : public TaskParameter
    {
        SEAD_RTTI_OVERRIDE(Parameter, TaskParameter)

    public:
        s32 controllerMax;
        IDelegate1<ControllerMgr*>* proc;

        Parameter()
            : controllerMax(0)
            , proc(nullptr)
        {
        }
    };

public:
    ControllerMgr();
    ControllerMgr(const TaskConstructArg& arg);
    virtual ~ControllerMgr() { }

    virtual void prepare();
    virtual void calc();

    void initialize(s32 controller_max, Heap* heap);
    void finalize();

    void initializeDefault(Heap* heap);
    void finalizeDefault();

    // TODO: Add/remove devices & controllers

    Controller* getControllerByOrder(ControllerDefine::ControllerId id, s32 index) const;
    ControlDevice* getControlDevice(ControllerDefine::DeviceId id) const;
    ControllerAddon* getControllerAddon(s32 index, ControllerDefine::AddonId id) const;

    template <typename T>
    T getControllerByOrderAs(s32 index) const;
    template <typename T>
    T getControlDeviceAs() const;
    template <typename T>
    T getControllerAddonAs(s32 index) const;

    s32 findControllerPort(const Controller* controller) const;

public:
    OffsetList<ControlDevice> mDevices;
    PtrArray<Controller> mControllers;
};
#ifdef cafe
static_assert(sizeof(ControllerMgr) == 0xE8, "sead::ControllerMgr size mismatch");
#endif // cafe

template <typename T>
T ControllerMgr::getControllerByOrderAs(s32 index) const
{
    for (PtrArray<Controller>::iterator it = mControllers.begin(); it != mControllers.end(); ++it)
    {
        T controller = DynamicCast<remove_pointer<T>::type>(&(*it));
        if (controller)
        {
            if (index == 0)
                return controller;

            index--;
        }
    }

    return nullptr;
}

template <typename T>
T ControllerMgr::getControlDeviceAs() const
{
    for (OffsetList<ControlDevice>::iterator it = mDevices.begin(); it != mDevices.end(); ++it)
    {
        T device = DynamicCast<remove_pointer<T>::type>(&(*it));
        if (device)
            return device;
    }

    return nullptr;
}

template <typename T>
T ControllerMgr::getControllerAddonAs(s32 index) const
{
    Controller* controller = mControllers.at(index);
    if (controller)
        return controller->getAddonAs<T>();

    return nullptr;
}

} // namespace sead

#endif // SEAD_CONTROLLER_MGR_H_
