#include "header.h"

// FlyWeightBuilder hold sharing properties which are heavy weight;
// FlyWeidght has reference to the properties;

class FlyWeightBuilder {
	vector<float> m_fontSizes;
	vector<string> m_fontNames;

public:
	FlyWeightBuilder(vector<float> fontSizes, vector<string> fontNames) : m_fontSizes(fontSizes), m_fontNames(fontNames) {};
	float getFontSize(int idx) {
		return m_fontSizes[idx];
	}

	string getFontName(int idx) {
		return m_fontNames[idx];
	}
};

class FlyWeightChar {
	int m_sizeIndex;
	int m_nameIndex;

public:
	FlyWeightChar(int sizeIndex, int nameIndex) : m_sizeIndex(sizeIndex), m_nameIndex(nameIndex) {};

	void createChar(FlyWeightBuilder& b) {
		float size = b.getFontSize(m_sizeIndex);
		string name = b.getFontName(m_nameIndex);

		cout << "created a char with size " << size <<  " and name " << name << endl;
	}
};

int main() {
	FlyWeightBuilder fwb({ 1.0, 3.5 }, { "small", "big" });

	FlyWeightChar flc1(0, 0);
	FlyWeightChar flc2(1, 1);

	flc1.createChar(fwb);
	flc2.createChar(fwb);

}