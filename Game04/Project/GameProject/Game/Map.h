#pragma once

#include "../Base/Base.h"
#include "GameData.h"

#define MAP_WIDTH       40
#define MAP_HEIGHT      22
#define MAP_TIP_SIZE    32

class Map : public Base {
private:
	CImage m_img;
	int stagedata[MAP_HEIGHT][MAP_WIDTH];
	int stagedata_base[MAP_HEIGHT][MAP_WIDTH];
public:
	Map();
	void Draw();
	//指定座標のチップ番号を取得
	int GetTipB(const CVector2D& pos);
	//指定列、指定行のマップチップを取得
	int GetTipB(int col, int raw);

	//指定座標のチップ番号を取得
	int GetTip(const CVector2D& pos);
	//指定列、指定行のマップチップを取得
	int GetTip(int col, int raw);
	void SetTip(const CVector2D& pos, int t);
	//マップとの当たり判定
	int CollisionMap(const CVector2D& pos);
	int CollisionMap(const CVector2D& pos, const CRect& rect);
};