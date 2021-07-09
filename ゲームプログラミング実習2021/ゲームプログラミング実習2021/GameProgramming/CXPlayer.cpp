#include "CXPlayer.h"
#include "CKey.h"
#include "CMatrix.h"

void CXPlayer::Update(){
	//Wキーが押されていれば歩き、押されていなければ待機
	if (CKey::Push('W')){
		ChangeAnimation(1, true, 60);
		mPosition += CVector(0.0f, 0.0f, 0.1f)*mMatrixRotate;
	}
	else{
		ChangeAnimation(0, true, 60);
	}
	//Aキーが押されていれば、Y軸の回転値に2加算する
	if (CKey::Push('A')){
		mRotation.mY += 2.0f;
	}
	//Dキーが押されていれば、Y軸の回転値を2減算する
	if (CKey::Push('D')){
		mRotation.mY -= 2.0f;
	}
	CXCharacter::Update();
}