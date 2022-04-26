#Two Pointer Algorithm
- Brute Force로 n<sup>2</sup> 걸기는 것을 n 안에 해결 할수 있게 해줌
- 배열에 Pointer 2개를 쓴다.
- 배열을 정렬한 다음에 left, right Pointer을 만들어 두 포인터 위치한 값의 합과 우리가 원하는 값을 비교해서 왼쪽 또는 오른쪽 포인터를 조정해서 우리가 원하는 값을 찾는거와 같이 활용할 수도 있고
- ~~~python
  // BOJ 2470
  n = int(input())
    data = list(map(int, input().split(" ")))

    data.sort()
    left, right = 0, len(data) - 1
    sol_left, sol_right = 0, 0
    standard = 2000000000

    while left != right:
    if data[left] + data[right] >= 0:
    if abs(data[left] + data[right]) < standard:
    sol_left, sol_right = left, right
    standard = abs(data[left] + data[right])
    right -= 1

        else:
            if abs(data[left] + data[right]) < standard:
                sol_left, sol_right = left, right
                standard = abs(data[left] + data[right])
            left += 1

    print(data[sol_left], data[sol_right])
  ~~~
- 배열에서 부분 배열이 특정 값을 만드는지를 조사 할때 쓰이기도 한다.
배열의 시작에 두 포인터를 위치 시켜 우리가 원하는 값보다 크면 left를 증가 시키고 visa versa
  (단, 배열 안의 값이 모두 음이 아닐때만)
- ~~~python
    // BOJ 2003
    N, M = map(int, input().split())
    nums = list(map(int, input().split()))

    left, right = 0, 1
    cnt = 0
    while right<=N and left<=right:

        sum_nums = nums[left:right]
        total = sum(sum_nums)

        if total == M:
            cnt += 1

            right += 1

        elif total < M:
            right += 1

        else:
            left += 1

    print(cnt)
  ~~~
- n<sup>3</sup> 상황에서 하나를 기준으로 잡고 Two Pointer를 사용해서 n<sup>2</sup>로 풀 수도 있다.
- ~~~python
    //LeetCode Three Sum
    from typing import List


    class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
    nums.sort()
    ans = list()

            for i in range(len(nums) - 2):
                goal = -nums[i]
                left = i + 1
                right = len(nums) - 1

                while left != right:
                    if nums[left] + nums[right] > goal:
                        right -= 1

                    elif nums[left] + nums[right] < goal:
                        left += 1

                    else:
                        ans.append([nums[i], nums[left], nums[right]])
                        left += 1

                    set__ = set(ans)

            return ans
  ~~~
- 특정 상황에서 쓰이는게 아니라 다방면으로 활용할수 있다.
- 포인터 2개를 쓰는 식으로 활용만 된다면 말이다.