/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */
#include "RobotImporter/ROS2RobotImporterEditorSystemComponent.h"
#include <ROS2EditorSystemComponent.h>
#include <ROS2ModuleInterface.h>

namespace ROS2
{
    class ROS2EditorModule : public ROS2ModuleInterface
    {
    public:
        AZ_RTTI(ROS2EditorModule, "{e23a1379-787c-481e-ad83-c0e04a3d06fe}", ROS2ModuleInterface);
        AZ_CLASS_ALLOCATOR(ROS2EditorModule, AZ::SystemAllocator, 0);

        ROS2EditorModule()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            // Add ALL components descriptors associated with this gem to m_descriptors.
            // This will associate the AzTypeInfo information for the components with the SerializeContext, BehaviorContext and
            // EditContext. This happens through the [MyComponent]::Reflect() function.
            m_descriptors.insert(
                m_descriptors.end(),
                { ROS2EditorSystemComponent::CreateDescriptor(), ROS2RobotImporterEditorSystemComponent::CreateDescriptor() });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         * Non-SystemComponents should not be added here
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<ROS2EditorSystemComponent>(),
                azrtti_typeid<ROS2RobotImporterEditorSystemComponent>(),
            };
        }
    };
} // namespace ROS2

AZ_DECLARE_MODULE_CLASS(Gem_ROS2, ROS2::ROS2EditorModule)
