#include "Rendererpch.h"
#include "CollisionSolver.h"
void SpriteRenderer::ColisionSolver::SolveColision(Collision collision)
{
	Transform* movingCollider = collision.collider1->m_Position != collision.transformObj1->m_Position ?
		collision.transformObj1 : collision.transformObj2;
	collision.CollisionNormal = movingCollider == collision.transformObj1 ? collision.CollisionNormal : -collision.CollisionNormal;
	movingCollider->m_Position += collision.CollisionNormal * collision.distance;
}
