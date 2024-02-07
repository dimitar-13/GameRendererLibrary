#include "Rendererpch.h"
#include "ColisionDetection.h"
#include"Log/Log.h"
bool SpriteRenderer::ColisionDetection::isColiding(const Colider& colider1, const Colider& colider2) //using AABB
{
	bool colisionX = (colider1.max.x >=  colider2.min.x)&&
				     (colider2.max.x >=  colider1.min.x);

	bool colisionY = (colider1.max.y >=  colider2.min.y)&&
					 (colider2.max.y >=  colider1.min.y);

	return  colisionX && colisionY;

}
bool SpriteRenderer::ColisionDetection::isColidingSAT(const Colider& colider1, const Colider& colider2) 
{
	/*glm::vec2 A = glm::vec2(1, 0);
	float max = 0;
	float min = 0;
	for (size_t i = 0; i < colider1.points.size(); i++)
	{
		if (max < glm::dot(A, colider1.points[i] - A)) {
			max = glm::dot(A, colider1.points[i] - A);
		}
	}
	colider1.points[0].x;

	float colider1widthInMeters = colider1.width * METER_SCALE_FACTOR;
	float colider1heightInMeters = colider1.height * METER_SCALE_FACTOR;
	float colider2widthInMeters = colider2.width * METER_SCALE_FACTOR;
	float colider2heightInMeters = colider2.height * METER_SCALE_FACTOR;

	bool colisionX = (colider1.originPosition.x + (colider1widthInMeters / 2) >= colider2.originPosition.x - (colider2widthInMeters / 2)) &&
		(colider2.originPosition.x + (colider1widthInMeters / 2) >= colider1.originPosition.x - (colider2widthInMeters / 2));
	bool colisionY = (colider1.originPosition.y + (colider1heightInMeters / 2) >= colider2.originPosition.y - (colider2heightInMeters / 2)) &&
		(colider2.originPosition.y + (colider1heightInMeters / 2) >= colider1.originPosition.y + (colider2heightInMeters / 2));

	return  colisionX && colisionY;*/
	return true;
}

