#include "Rendererpch.h"
#include "Camera.h"

glm::mat4& SpriteRenderer::OrthographicCamera::GetViewProjectionMatrix()
{
    CalculateLookAtMatrix();
    return this->viewProjection; 
}

void SpriteRenderer::OrthographicCamera::CalculateLookAtMatrix()
{

    glm::vec3 DirVec = glm::vec3(0) - this->position;
    glm::vec3 front = glm::length(DirVec) >1 ? glm::normalize(DirVec): DirVec;
    glm::vec3 tempUp(0, 1, 0);

    glm::vec3 right = glm::cross(front,tempUp);
    glm::vec3 up = glm::cross(right,front);

    right = glm::length(right) > 1 ? glm::normalize(right) : right;
    up = glm::length(up) > 1 ? glm::normalize(up) : up;


    this->lookAtMatrix = glm::mat4(1);
    this->lookAtMatrix[0][0] = right.x;
    this->lookAtMatrix[1][0] = right.y;
    this->lookAtMatrix[2][0] = right.z;

    this->lookAtMatrix[0][1] = up.x;
    this->lookAtMatrix[1][1] = up.y;
    this->lookAtMatrix[2][1] = up.z;

    this->lookAtMatrix[0][2] = front.x;
    this->lookAtMatrix[1][2] = front.y;
    this->lookAtMatrix[2][2] = front.z;

    this->lookAtMatrix[0][3] = -this->position.x;
    this->lookAtMatrix[1][3] = -this->position.y;
    this->lookAtMatrix[2][3] = -this->position.z;

    //return this->lookAtMatrix
    this->lookAtMatrix = glm::lookAt(position, glm::vec3(0), tempUp);
    this->viewProjection = this->projection * this->lookAtMatrix;
    //return  this->lookAtMatrix;
}
