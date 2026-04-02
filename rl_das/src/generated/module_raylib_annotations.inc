// GENERATED — do not edit manually.
// Regenerate with: python3 tools/gen_raylib_bindings.py

#pragma once

// --- Defined structs (ManagedStructureAnnotation with field bindings) ---

MAKE_TYPE_FACTORY(AutomationEvent, AutomationEvent)
struct RaylibAutomationEventAnnotation : das::ManagedStructureAnnotation<AutomationEvent> {
    RaylibAutomationEventAnnotation(das::ModuleLibrary &lib)
        : ManagedStructureAnnotation("AutomationEvent", lib) {
        this->cppName = "AutomationEvent";

        addField<DAS_BIND_MANAGED_FIELD(frame)>("frame", "frame");
        addField<DAS_BIND_MANAGED_FIELD(type)>("vtype", "type");
    }
};

MAKE_TYPE_FACTORY(AutomationEventList, AutomationEventList)
struct RaylibAutomationEventListAnnotation : das::ManagedStructureAnnotation<AutomationEventList> {
    RaylibAutomationEventListAnnotation(das::ModuleLibrary &lib)
        : ManagedStructureAnnotation("AutomationEventList", lib) {
        this->cppName = "AutomationEventList";

        addField<DAS_BIND_MANAGED_FIELD(capacity)>("capacity", "capacity");
        addField<DAS_BIND_MANAGED_FIELD(count)>("count", "count");
    }
};

MAKE_TYPE_FACTORY(Camera2D, Camera2D)
struct RaylibCamera2DAnnotation : das::ManagedStructureAnnotation<Camera2D> {
    RaylibCamera2DAnnotation(das::ModuleLibrary &lib)
        : ManagedStructureAnnotation("Camera2D", lib) {
        this->cppName = "Camera2D";

        addField<DAS_BIND_MANAGED_FIELD(offset)>("offset", "offset");
        addField<DAS_BIND_MANAGED_FIELD(target)>("target", "target");
        addField<DAS_BIND_MANAGED_FIELD(rotation)>("rotation", "rotation");
        addField<DAS_BIND_MANAGED_FIELD(zoom)>("zoom", "zoom");
    }
};

MAKE_TYPE_FACTORY(Camera3D, Camera3D)
struct RaylibCamera3DAnnotation : das::ManagedStructureAnnotation<Camera3D> {
    RaylibCamera3DAnnotation(das::ModuleLibrary &lib)
        : ManagedStructureAnnotation("Camera3D", lib) {
        this->cppName = "Camera3D";

        addField<DAS_BIND_MANAGED_FIELD(position)>("position", "position");
        addField<DAS_BIND_MANAGED_FIELD(target)>("target", "target");
        addField<DAS_BIND_MANAGED_FIELD(up)>("up", "up");
        addField<DAS_BIND_MANAGED_FIELD(fovy)>("fovy", "fovy");
        addField<DAS_BIND_MANAGED_FIELD(projection)>("projection", "projection");
    }
};

MAKE_TYPE_FACTORY(FilePathList, FilePathList)
struct RaylibFilePathListAnnotation : das::ManagedStructureAnnotation<FilePathList> {
    RaylibFilePathListAnnotation(das::ModuleLibrary &lib)
        : ManagedStructureAnnotation("FilePathList", lib) {
        this->cppName = "FilePathList";

        addField<DAS_BIND_MANAGED_FIELD(count)>("count", "count");
    }
};

MAKE_TYPE_FACTORY(ModelSkeleton, ModelSkeleton)
struct RaylibModelSkeletonAnnotation : das::ManagedStructureAnnotation<ModelSkeleton> {
    RaylibModelSkeletonAnnotation(das::ModuleLibrary &lib)
        : ManagedStructureAnnotation("ModelSkeleton", lib) {
        this->cppName = "ModelSkeleton";

        addField<DAS_BIND_MANAGED_FIELD(boneCount)>("boneCount", "boneCount");
        addField<DAS_BIND_MANAGED_FIELD(bindPose)>("bindPose", "bindPose");
    }
};

MAKE_TYPE_FACTORY(VrDeviceInfo, VrDeviceInfo)
struct RaylibVrDeviceInfoAnnotation : das::ManagedStructureAnnotation<VrDeviceInfo> {
    RaylibVrDeviceInfoAnnotation(das::ModuleLibrary &lib)
        : ManagedStructureAnnotation("VrDeviceInfo", lib) {
        this->cppName = "VrDeviceInfo";

        addField<DAS_BIND_MANAGED_FIELD(hResolution)>("hResolution", "hResolution");
        addField<DAS_BIND_MANAGED_FIELD(vResolution)>("vResolution", "vResolution");
        addField<DAS_BIND_MANAGED_FIELD(hScreenSize)>("hScreenSize", "hScreenSize");
        addField<DAS_BIND_MANAGED_FIELD(vScreenSize)>("vScreenSize", "vScreenSize");
        addField<DAS_BIND_MANAGED_FIELD(eyeToScreenDistance)>("eyeToScreenDistance", "eyeToScreenDistance");
        addField<DAS_BIND_MANAGED_FIELD(lensSeparationDistance)>("lensSeparationDistance", "lensSeparationDistance");
        addField<DAS_BIND_MANAGED_FIELD(interpupillaryDistance)>("interpupillaryDistance", "interpupillaryDistance");
    }
};

MAKE_TYPE_FACTORY(VrStereoConfig, VrStereoConfig)
struct RaylibVrStereoConfigAnnotation : das::ManagedStructureAnnotation<VrStereoConfig> {
    RaylibVrStereoConfigAnnotation(das::ModuleLibrary &lib)
        : ManagedStructureAnnotation("VrStereoConfig", lib) {
        this->cppName = "VrStereoConfig";
    }
};

