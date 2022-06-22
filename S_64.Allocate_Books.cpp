def check_allocation(arr,std,mx_books):
    sm_pages=0
    students=1
    n=len(arr)
    for i in range(n):
        if sm_pages+arr[i]>mx_books:
            students+=1
            sm_pages=arr[i]

            if students>std:
                return False
        else:
            sm_pages+=arr[i]
    return True

class Solution:
	# @param A : list of integers
	# @param B : integer
	# @return an integer
	def books(self, A, B):
        if B>len(A):
            return -1
        mn_pages=max(A)
        mx_pages=sum(A)
        while mn_pages<mx_pages:
            mid=(mn_pages+mx_pages)//2
            if check_allocation(A,B,mid):
                mx_pages=mid
            else:
                mn_pages=mid+1
        return mx_pages
