class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        size_t index = 0;
        for (size_t i =0; i < n ; i++){
            if ( A[i] != elem){
                A[index++] = A[i];
            }
        }
        return index;
    }
};