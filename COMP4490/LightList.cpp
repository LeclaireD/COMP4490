#include "LightList.h"

LightList::LightList() {

}
void LightList::lightAdd(Light *light) {
	lights[currPos] = light;
	currPos++;
}
int LightList::getSize() {
	return currPos;
}
Light* LightList::getLight(int i) {
	return lights[i];
}