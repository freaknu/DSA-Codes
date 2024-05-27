class Greedy {
public:
	pair<int, vector<int>> kadane_Algo(int arr[], int n) {
		if (n == 0) {
			return make_pair(0, vector<int>());
		}

		int maxSum = -1e9;
		int currentSum = 0;
		int start = 0;
		int maxStart = 0;
		int maxEnd = -1;

		for (int i = 0; i < n; i++) {
			currentSum += arr[i];
			if (currentSum > maxSum) {
				maxSum = currentSum;
				maxStart = start;
				maxEnd = i;
			}
			if (currentSum < 0) {
				currentSum = 0;
				start = i + 1;
			}
		}
		vector<int> subArray;
		for (int i = maxStart; i <= maxEnd; i++) {
			subArray.push_back(arr[i]);
		}

		return make_pair(maxSum, subArray);
	}
};
