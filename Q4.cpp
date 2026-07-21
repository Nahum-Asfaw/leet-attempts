class Solution {
public:
    double Q5(vector<int>& nums1, vector<int>& nums2, int n, int m, int a, int b) {
        // I GIVE UP...

        cout << "n:" << n << " m:" << m << endl;
        cout << "a:" << a << " b:" << b << endl;
        
        // for array = 0
        if (m == 0){ 
            return nums1[a + n - 1];
        }
        else if (n == 0){
            return nums2[b + m - 1];
        }

        if (n == 1 && m == 1){ // base
            cout << "HERE" << endl;
            cout << "a + n - 1 = " << (a + n -1) << endl;
            cout << "b + m - 1 = " << (b + m -1) << endl;
            
            cout << "return value: " << "(" << nums1[a + n -1] << " + " << nums2[b + m - 1] << ")*(0.5) = " << (nums1[a + n - 1] + nums2[b + m - 1])*(0.5) << endl;
            return (nums1[a + n - 1] + nums2[b + m - 1])*(0.5);
        }
        

        int k = ceil((0.5)*n);
        int l = ceil((0.5)*m);
        //cout << "k:" << k << " l:" << l << endl;
        int k_floor = floor((0.5)*n);
        int l_floor = floor((0.5)*m);
        //cout << "nums1[a+k]:" << nums1[a+k] << endl;
        //cout << "nums2[b+l]:" << nums2[b+l] << endl;

        if (nums1[a + k - 1] <= nums2[b + l - 1])
            return Q5(nums1, nums2, k, l, a + k_floor, b);
        else
            return Q5(nums1, nums2, k, l, a, b + l_floor);
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return Q5(nums1, nums2, nums1.size(), nums2.size(), 0, 0);
    }
};