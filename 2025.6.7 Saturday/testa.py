import sys
from collections import defaultdict

def main():
    while True:
        try:
            line = sys.stdin.readline()
            if not line:
                break
            n = int(line.strip())
            for _ in range(n):
                a, p, y = map(int, sys.stdin.readline().split())
                families.append((a, p, y))
        except EOFError:
            break

        sorted_families = sorted(families, key=lambda x: (x[2], x[0]))

        age_year_p = defaultdict(set)
        for a, p, y in sorted_families:
            if (a, y) not in age_year_p:
                age_year_p[(a, y)] = set()
            age_year_p[(a, y)].add(p)

        pre_time_points = {}
        for a in age_year_p:
            current_times = defaultdict(dict)
            for family in sorted_families:
                if (family[0] == a and family[2] == (a, p, _)):
                    continue
                else:
                    pass
            pre_time_points[a] = current_times

        x, s = None, 0
        while True:
            try:
                n = int(sys.stdin.readline())
                for _ in range(n):
                    a, p, y = map(int, sys.stdin.readline().split())
                    families.append((a, p, y))
            except EOFError:
                break

            if x is None or not isinstance(x, int) or x < 1:
                print(0)
                return

            current_age = a
            if current_age not in age_year_p:
                print(0)
                return

            year_times = pre_time_points[current_age]
            for y in year_times:
                time_points = year_times[y]
                for t, p in enumerate(time_points):
                    if p == x and t >= s:
                        count += 1

        print(count)

if __name__ == '__main__':
    main()
