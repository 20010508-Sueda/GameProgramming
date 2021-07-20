#include "CXPlayer.h"
#include "CKey.h"

void CXPlayer::Update(){
	if (mAnimationIndex == 3){
		if (mAnimationFrame >= mAnimationFrameSize){
			ChangeAnimation(4, false, 30);
		}
	}
	else if (mAnimationIndex == 4){
		if (mAnimationFrame >= mAnimationFrameSize){
			ChangeAnimation(0, true, 60);
		}
	}
	else {
		//スペースキーを押すと攻撃し、攻撃した後は、元の姿勢へ戻し、待機する
		if (CKey::Once(' ')){
			ChangeAnimation(3, false, 30);
		}	
		//Wキーが押されていれば歩き、押されていなければ待機
		else if (CKey::Push('W')){
			ChangeAnimation(1, true, 60);
			mPosition += CVector(0.0f, 0.0f, 0.1f)*mMatrixRotate;
		}
		else{
			ChangeAnimation(0, true, 60);
		}
		//Aキーが押されていれば、Y軸の回転値を2加算する
		if (CKey::Push('A')){
			mRotation.mY += 2.0f;
		}
		//Dキーが押されていれば、Y軸の回転値を2減算する
		else if (CKey::Push('D')){
			mRotation.mY -= 2.0f;
		}
	}
	CXCharacter::Update();
}