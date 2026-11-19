#include <stdio.h>

char grade_if(int marks) {
    if (marks < 0 || marks > 100) return '?';
    if (marks >= 90) return 'S';
    else if (marks >= 80) return 'A';
    else if (marks >= 70) return 'B';
    else if (marks >= 60) return 'C';
    else if (marks >= 50) return 'D';
    else return 'F';
}

char grade_switch(int marks) {
    if (marks < 0 || marks > 100) return '?';
    switch (marks / 10) {
        case 10: case 9: return 'S';
        case 8: return 'A';
        case 7: return 'B';
        case 6: return 'C';
        case 5: return 'D';
        default: return 'F';
    }
}

int main(void) {
    int marks[] = {100, 95, 83, 50, 49, -5, 0, 89, 90, 101};
    int n = (int)(sizeof marks / sizeof marks[0]);
    for (int i = 0; i < n; ++i)
        printf("%d:%c (switch:%c)\n",
               marks[i], grade_if(marks[i]), grade_switch(marks[i]));
    return 0;
}
