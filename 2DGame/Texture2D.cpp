#include "Texture2D.h"

void Texture2D::TextureDraw(Texture2D* srcText, int32_t x, int32_t y) {
	// инициализация параметров для memmove
	int outerXEnd = x + srcText->width;
	size_t distXSkip = 0;
	size_t sourceXSkip = 0;
	size_t xTransport = 0;

	if (outerXEnd < 0 || x >(int32_t)width) {
		return;
	}
	if (x >= 0 && outerXEnd <= width) {
		xTransport = srcText->width;
		distXSkip = x;
	}
	if (x >= 0 && outerXEnd >= width) {
		xTransport = width - x;
		distXSkip = x;
	}
	if (x < 0 && outerXEnd <= width) {
		xTransport = outerXEnd;
		sourceXSkip = -x;
	}
	if (x < 0 && outerXEnd >= width) {
		xTransport = width;
		sourceXSkip = -x;
	}

	int outerYEnd = y + srcText->height;
	size_t distYSkip = 0;
	size_t sourceYSkip = 0;
	size_t yTransport = 0;

	if (outerYEnd < 0 || y >(int32_t)height) {
		return;
	}
	if (y >= 0 && outerYEnd <= height) {
		yTransport = srcText->height;
		distYSkip = y;
	}
	if (y >= 0 && outerYEnd >= height) {
		yTransport = height - y;
		distYSkip = y;
	}
	if (y < 0 && outerYEnd <= height) {
		yTransport = outerYEnd;
		sourceYSkip = -y;
	}
	if (y < 0 && outerYEnd >= height) {
		yTransport = height;
		sourceYSkip = -y;
	}

	// move bytes from image to image with x,y offset
	for (size_t i = 0; i < yTransport; i++) {
		std::memmove(data + (distYSkip + i) * width + distXSkip, srcText->data + (sourceYSkip + i) * srcText->width + sourceXSkip, xTransport);
	}
}
