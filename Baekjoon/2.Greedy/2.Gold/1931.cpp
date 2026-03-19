#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    // 입출력 최적화
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    // 회의 정보 vector
    std::vector<std::pair<int, int>> meetings(n);

    for (int i = 0; i < n; ++i)
    {
        std::cin >> meetings[i].second >> meetings[i].first;
    }

    // 종료 시간 기준 오름차순 정렬
    std::sort(meetings.begin(), meetings.end());

    int count = 0;
    int current_end_time = 0;
    const int num_meetings = meetings.size();

    // 최대 배정 가능 회의 개수 계산
    for (int i = 0; i < num_meetings; ++i)
    {
        if (meetings[i].second >= current_end_time)
        {
            ++count;
            current_end_time = meetings[i].first;
        }
    }

    // 타겟 출력
    std::cout << count << "\n";

    return 0;
}
