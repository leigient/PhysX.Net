#pragma once

#include "Controller.h"
#include "Element Collection.h"

using namespace System;
UsingFrameworkNamespace

namespace StillDesign
{
	namespace PhysX
	{
		ref class Scene;
		ref class ControllerDescription;
		
		public ref class ControllerManager : StillDesign::PhysX::IDisposable
		{
			public:
				//ref class ControllerCollection : ReadOnlyElementCollection<StillDesign::PhysX::Controller^>
				//{
				//	
				//};
				
				virtual event EventHandler^ onDisposing;
				virtual event EventHandler^ onDisposed;
				
			private:
				NxControllerManager* _manager;
				StillDesign::PhysX::Scene^ _scene;
				
				ElementCollection< StillDesign::PhysX::Controller^ >^ _controllers;
				
				Object^ _userData;
				
				String^ _name;
			
			internal:
				ControllerManager( NxControllerManager* manager, StillDesign::PhysX::Scene^ scene );
			public:
				~ControllerManager();
			protected:
				!ControllerManager();
			public:
				property bool IsDisposed
				{
					virtual bool get();
				}
			
			public:
				/// <summary></summary>
				StillDesign::PhysX::Controller^ CreateController( ControllerDescription^ controllerDescription );
				
				/// <summary></summary>
				void UpdateControllers();
				
				//
				
				/// <summary></summary>
				property StillDesign::PhysX::Scene^ Scene
				{
					StillDesign::PhysX::Scene^ get();
				}
				
				/// <summary>Gets the Collection of Controller</summary>
				property ReadOnlyList< Controller^ >^ Controllers
				{
					ReadOnlyList< Controller^ >^ get();
				}
				
				/// <summary></summary>
				property String^ Name
				{
					String^ get();
					void set( String^ value );
				}
				
				/// <summary></summary>
				property Object^ UserData
				{
					virtual Object^ get();
					virtual void set( Object^ value );
				}
			
			internal:
				property NxControllerManager* UnmanagedPointer
				{
					NxControllerManager* get();
				}
		};
	};
};