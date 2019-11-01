#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size);

int main(void)
{
    int a[] = {1,3};
    int b[] = {2};

    double c = findMedianSortedArrays(a, sizeof(a)/sizeof(int), b, sizeof(b)/sizeof(int));

    printf("%.f\r\n", c);
    return 0;
}


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){

    int *p = malloc((sizeof(int)* (nums1Size + nums2Size)));
    if (p == NULL){
        return 0;
    }

    printf("%d-%d\n", nums1Size, nums2Size);
    int i = 0, j = 0, k = 0;

    while (i < nums1Size && j < nums2Size){
        if (nums1[i] < nums2[j]){
            *(p+k)= nums1[i++];
        }else{
            *(p+k) = nums2[j++];
        }
        ++k;
    }

    while(i<nums1Size){
        p[k++] = nums1[i++];
    }

    while(j<nums2Size){
        p[k++] = nums2[j++];
    }

    i = 0; j = k - 1;
    int mid = i + (j - i) / 2;

    printf("mid %d\n", mid);

    if (mid %2 == 0){
        return *(p+mid -1);
    }else{
        return (*(p+mid -1) + *(p+mid) )/2.0;
    }
}

