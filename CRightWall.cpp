#include "CRightWall.h"

CRightWall::CRightWall(float iwidth, float iheight, float idepth, D3DXCOLOR color)
	: CWall(iwidth, iheight, idepth, color) {
}

bool CRightWall::hasIntersected(CSphere& ball) const noexcept {
	if (ball.getPosition().z > this->center_z - (this->m_depth / 2) &&
		ball.getPosition().z < this->center_z + (this->m_depth / 2)) {
		if (ball.getPosition().x + ball.getRadius() > this->center_x - (this->m_width / 2)) {
			return true;
		}
	}
	return false;
}

void CRightWall::hitBy(CSphere& ball) noexcept {
	if (hasIntersected(ball)) {
		this->adjustPosition(ball);
		ball.setPower(-ball.getVelocity_X() * (1 - LOSS_RATIO), ball.getVelocity_Z() * (1 - LOSS_RATIO));
	}
}