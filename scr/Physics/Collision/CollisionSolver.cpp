#include "Rendererpch.h"
#include "CollisionSolver.h"
void SpriteRenderer::ColisionSolver::SolveColision(Collision collision)
{
	if (collision.collider1->m_isTrigger || collision.collider2->m_isTrigger) return;

	Transform* movingCollider = collision.collider1->m_Position != collision.transformObj1->m_Position ?
		collision.transformObj1 : collision.transformObj2;

	movingCollider->m_Position += collision.CollisionNormal * collision.distance;




	

	
		//collision.transformObj1->m_Position += collision.CollisionNormal*collision.distance;
	

	//TODO:Make it so it checks for both coliders to find the moving one and think about 2 moving
	//colliders
	//if (collision.collider1->lastPosition != collision.collider1->originPosition)
	//{
	//	glm::vec2 ColisionNormal(0);
	//	//Check for offset on Y
	//	if (collision.colider2->lastPosition.y != collision.colider2->originPosition.y)
	//	{
	//			//Top
	//			if (collision.colider1->min.y < collision.colider2->max.y && 
	//				collision.colider2->min.y < collision.colider1->max.y &&
	//				collision.colider2->min.y < collision.colider1->min.y)
	//			{
	//				ColisionNormal.y -= collision.colider2->max.y - collision.colider1->min.y;
	//			}
	//			//Bottom
	//			else if (collision.colider2->min.y < collision.colider1->max.y && 
	//					 collision.colider2->max.y > collision.colider1->max.y &&
	//					 collision.colider2->max.y > collision.colider1->min.y)
	//			{
	//				ColisionNormal.y += collision.colider1->max.y - collision.colider2->min.y;
	//			}
	//	}
	//	//Check for offset on X
	//	if (collision.colider2->lastPosition.x != collision.colider2->originPosition.x)
	//	{
	//			//Right
	//			if (collision.colider2->max.x > collision.colider1->min.x && 
	//				collision.colider2->max.x < collision.colider1->max.x &&
	//				collision.colider2->min.x < collision.colider1->max.x)
	//			{
	//				ColisionNormal.x -= collision.colider2->max.x - collision.colider1->min.x;
	//			}
	//			//Left
	//			else if (collision.colider2->min.x < collision.colider1->max.x &&
	//					 collision.colider2->min.x > collision.colider1->min.x &&
	//					 collision.colider2->max.x > collision.colider1->min.x)
	//			{
	//				ColisionNormal.x += collision.colider1->max.x - collision.colider2->min.x;
	//			}
	//	}

	//	if (collision.colider2->lastPosition.x != collision.colider2->originPosition.x &&
	//		collision.colider2->lastPosition.y != collision.colider2->originPosition.y)
	//	{
	//		if (std::min(glm::abs(ColisionNormal.x), std::abs(ColisionNormal.y)) == std::abs(ColisionNormal.x)&&
	//			ColisionNormal.x !=0)
	//		{
	//			collision.colider2->transform->m_Position.x += ColisionNormal.x;

	//		}
	//		else if (std::min(glm::abs(ColisionNormal.x), std::abs(ColisionNormal.y)) == std::abs(ColisionNormal.y) &&
	//			ColisionNormal.y != 0)
	//		{
	//			collision.colider2->transform->m_Position.y += ColisionNormal.y;
	//		}
	//	}
	//	else
	//	{
	//	collision.colider2->transform->m_Position += ColisionNormal;
	//	}
	//	
	//	collision.colider2->UpdateTransfrom();
	//}


}
