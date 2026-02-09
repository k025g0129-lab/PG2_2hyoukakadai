#include "Function.h"

int circleToCircleHitJudge(Vector2 selfPos, Vector2 targetPos,float selfRadius, float targetRadius) {

    float dx = selfPos.x - targetPos.x;
    float dy = selfPos.y - targetPos.y;

    float distanceSq = dx * dx + dy * dy;
    float radiusSum = selfRadius + targetRadius;

    if (distanceSq <= radiusSum * radiusSum) {
        return true;
    }

	return false;
}
