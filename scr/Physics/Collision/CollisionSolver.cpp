#include "Rendererpch.h"
#include "CollisionSolver.h"
void SpriteRenderer::CollisionSolver::SolveCollision(Collision collision)
{

	Transform* movingColliderTransform = collision.collider1->m_Position != collision.transformObj1->m_Position ?
		collision.transformObj1 : collision.transformObj2;


	collision.CollisionNormal = movingColliderTransform == collision.transformObj1 ?
		collision.CollisionNormal : -collision.CollisionNormal;

	movingColliderTransform->m_Position += collision.CollisionNormal * collision.distance;
}
