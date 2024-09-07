#pragma once
#include "./ICollider.h"
#include "vector"
namespace Collision {
	class CollisionService {
	private:
		std::vector<ICollider*> m_colliders;

		void processCollision();
		void doCollision(int indexI, int indexJ);
		bool hasCollisionOccurred(int indexI, int indexJ);
		bool areValidColliders(int indexI, int indexJ);

	public:
		CollisionService();
		~CollisionService();

		void initialize();
		void update();
		void render();

		void addCollider(ICollider* collider);
		void removeCollider(ICollider* collider);

		void destroy();
	};
}