#include "Rendererpch.h"
#include "Colider.h"
#include"MetricHelper.h"
#include "CollisionDetection.h" 

SpriteRenderer::Collision SpriteRenderer::CircleCollider::TestForCollision(Collider* collider, Transform* callerTransform,
	Transform* toBeTestedTransform)
{
	return collider->TestForCollision(this, toBeTestedTransform,callerTransform);
}

SpriteRenderer::Collision SpriteRenderer::CircleCollider::TestForCollision(CircleCollider* CircleCollider2, Transform* callerTransform,
	Transform* toBeTestedTransform)
{
	return CollisionDetectionFuncs::TestForCollision(this,CircleCollider2, callerTransform, toBeTestedTransform);
}

SpriteRenderer::Collision SpriteRenderer::CircleCollider::TestForCollision(SquareCollider* SquareCollider, Transform* callerTransform,
	Transform* toBeTestedTransform)
{

	return CollisionDetectionFuncs::TestForCollision(SquareCollider,this, toBeTestedTransform, callerTransform);
}

SpriteRenderer::Collision SpriteRenderer::SquareCollider::TestForCollision(Collider* collider, Transform* callerTransform,
	Transform* toBeTestedTransform)
{
	return collider->TestForCollision(this, toBeTestedTransform,callerTransform);
}

SpriteRenderer::Collision SpriteRenderer::SquareCollider::TestForCollision(SquareCollider* SquareCollider2, Transform* callerTransform,
	Transform* toBeTestedTransform)
{
	return CollisionDetectionFuncs::TestForCollision(this,SquareCollider2, callerTransform, toBeTestedTransform);
}
