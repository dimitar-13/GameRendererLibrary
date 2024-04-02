#pragma once
#include"Rendererpch.h"
#include"GameObject.h"
namespace SpriteRenderer {
	class ScriptSystem;
	class ScriptComponent;

	/// <summary>
	///Base class for creating a script behavior of an game object.
	///Class provides virtual method for on frame update,on object creation and for object deletion.
	/// </summary>
	class ScriptableObject {
		protected:
			friend class ScriptComponent;
			friend class ScriptSystem;
			/// <summary>
			/// Called every frame.
			/// </summary>
			virtual void OnUpdate() { };
			/// <summary>
			/// Called on creation of the game object.
			/// *For now its only on game start
			/// </summary>
			virtual void OnStart() { };
			/// <summary>
			/// Called on game object deletion.
			/// </summary>
			virtual void OnDelete() { };
			/// <summary>
			/// Way to get game object reference.
			/// </summary>
			/// <returns>Retruns a pointer to the game object that have this script attached.</returns>
			const GameObject *const GetGameObject() const { return this->gameObject; }
		private:
			friend class ScriptComponent;
			/// <summary>
			/// Binds game object to the script.
			/// </summary>
			/// <param name="gameObj"><Object to be bound./param>
			void BindScript(const GameObject * gameObj) { gameObject = gameObj; }
			const GameObject * gameObject;
	};

	

}