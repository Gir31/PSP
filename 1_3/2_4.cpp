#include <iostream>
#include <vector>

using namespace std;

struct Food {
	int car;
	int pro;
	int fat;
	int cal;
};

bool calCar(int car, int stdCar) {
	return stdCar >= car;
}

bool calPro(int pro, int stdPro) {
	return stdPro <= pro;
}

bool calFat(int fat, int stdFat) {
	return stdFat >= fat;
}

bool calCal(int cal, int stdCal) {
	return stdCal >= cal;
}

int main()
{
	int n = 0;
	vector<Food> foods;

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		Food food;

		cin >> food.car >> food.pro >> food.fat;

		food.cal = food.car + food.pro + food.fat;

		foods.push_back(food);
	}

	int stdCar = 0, stdPro = 0, stdFat = 0, stdCal = 0;

	cin >> stdCar >> stdPro >> stdFat >> stdCal;

	int diets = 0;

	for (int food1 = 0; food1 < n; ++food1)
	{
		if (calCar(foods[food1].car, stdCar))
		{
			if (calPro(foods[food1].pro, stdPro))
			{
				if (calFat(foods[food1].fat, stdFat))
				{
					if (calCal(foods[food1].cal, stdCal))
					{
						++diets;
					}
				}
			}
		}

		for (int food2 = food1 + 1; food2 < n; ++food2)
		{
			if (calCar(foods[food1].car + foods[food2].car, stdCar))
			{
				if (calPro(foods[food1].pro + foods[food2].pro, stdPro))
				{
					if (calFat(foods[food1].fat + foods[food2].fat, stdFat))
					{
						if (calCal(foods[food1].cal + foods[food2].cal, stdCal))
						{
							++diets;
						}
					}
				}
			}

			for (int food3 = food2 + 1; food3 < n; ++food3)
			{
				if (calCar(foods[food1].car + foods[food2].car + foods[food3].car, stdCar))
				{
					if (calPro(foods[food1].pro + foods[food2].pro + foods[food3].pro, stdPro))
					{
						if (calFat(foods[food1].fat + foods[food2].fat + foods[food3].fat, stdFat))
						{
							if (calCal(foods[food1].cal + foods[food2].cal + foods[food3].cal, stdCal))
							{
								++diets;
							}
						}
					}
				}
			}
		}
	}

	cout << diets;

}