#include "CXPlayer.h"
#include "CKey.h"

void CXPlayer::Update(){
	//Wキーが押されていれば歩き、押されていなければ待機
	if (CKey::Push('W')){
		ChangeAnimation(1, true, 60);
		mPosition.mZ += 0.1f;
	}
	else{
		ChangeAnimation(0, true, 60);
	}
	CXCharacter::Update();
}