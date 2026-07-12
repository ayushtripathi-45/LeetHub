class Solution {
public:
    void merge(vector<int>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<int> L(n1);
        vector<int> R(n2);

        for (int i = 0; i < n1; i++) L[i] = arr[left + i];
        for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    void mergeSort(vector<int>& arr, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;

            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);

            merge(arr, left, mid, right);
        }
    }

    int binarySearch(vector<int>& uniqueArr, int target) {
        int low = 0, high = uniqueArr.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (uniqueArr[mid] == target) {
                return mid + 1;
            } else if (uniqueArr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }

    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return {};

        vector<int> sortedArr = arr;
        mergeSort(sortedArr, 0, n - 1);

        vector<int> uniqueArr;
        uniqueArr.push_back(sortedArr[0]);
        for (int i = 1; i < n; i++) {
            if (sortedArr[i] != sortedArr[i - 1]) {
                uniqueArr.push_back(sortedArr[i]);
            }
        }

        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            result[i] = binarySearch(uniqueArr, arr[i]);
        }

        return result;
    }
};