#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 30
#define SUBJECTS 3

// Структура для зберігання даних про студента
typedef struct
{
    char surname[13];
    int group;
    int web_tech;
    int ukr_lang;
    int design_info_systems;
} Student;

// Функції для виконання запитів
void find_debtors(Student students[], int num_students);
double calculate_percentage_good_students(Student students[], int num_students);
void best_subject(Student students[], int num_students);
void worst_group(Student students[], int num_students);

int main()
{
    int num_students;
    Student students[MAX_STUDENTS];

    // Введення кількості студентів
    printf("Enter the number of students (max %d): ", MAX_STUDENTS);
    scanf("%d", &num_students);

    if (num_students > MAX_STUDENTS)
    {
        printf("Too many students!\n");
        return 1;
    }

    // Введення даних про студентів
    for (int i = 0; i < num_students; i++)
    {
        printf("Enter data for student %d:\n", i + 1);
        printf("Surname: ");
        scanf("%s", students[i].surname);
        printf("Group number (1-4): ");
        scanf("%d", &students[i].group);
        printf("Web Technologies score: ");
        scanf("%d", &students[i].web_tech);
        printf("Ukrainian Language score: ");
        scanf("%d", &students[i].ukr_lang);
        printf("Design Information Systems score: ");
        scanf("%d", &students[i].design_info_systems);
    }

    // Виконання запитів
    printf("\nStudents with debts:\n");
    find_debtors(students, num_students);

    double percent_good_students = calculate_percentage_good_students(students, num_students);
    printf("\nPercentage of students with all 'good' or 'excellent' marks: %.2f%%\n", percent_good_students);

    printf("\nBest subject based on average score:\n");
    best_subject(students, num_students);

    printf("\nGroup with worst performance:\n");
    worst_group(students, num_students);

    return 0;
}

// Функція для виведення студентів з заборгованістю (бали < 60)
void find_debtors(Student students[], int num_students)
{
    for (int i = 0; i < num_students; i++)
    {
        if (students[i].web_tech < 60 || students[i].ukr_lang < 60 || students[i].design_info_systems < 60)
        {
            printf("%s\n", students[i].surname);
        }
    }
}

// Функція для підрахунку проценту студентів, які здали всі екзамени на відмінно або добре (>= 75)
double calculate_percentage_good_students(Student students[], int num_students)
{
    int count_good_students = 0;

    for (int i = 0; i < num_students; i++)
    {
        if (students[i].web_tech >= 75 && students[i].ukr_lang >= 75 && students[i].design_info_systems >= 75)
        {
            count_good_students++;
        }
    }

    return (double)count_good_students / num_students * 100;
}

// Функція для визначення предмета з найкращими середніми результатами
void best_subject(Student students[], int num_students)
{
    double total_web_tech = 0, total_ukr_lang = 0, total_design_info_systems = 0;

    for (int i = 0; i < num_students; i++)
    {
        total_web_tech += students[i].web_tech;
        total_ukr_lang += students[i].ukr_lang;
        total_design_info_systems += students[i].design_info_systems;
    }

    double avg_web_tech = total_web_tech / num_students;
    double avg_ukr_lang = total_ukr_lang / num_students;
    double avg_design_info_systems = total_design_info_systems / num_students;

    if (avg_web_tech > avg_ukr_lang && avg_web_tech > avg_design_info_systems)
    {
        printf("Web Technologies\n");
    }
    else if (avg_ukr_lang > avg_web_tech && avg_ukr_lang > avg_design_info_systems)
    {
        printf("Ukrainian Language\n");
    }
    else
    {
        printf("Design Information Systems\n");
    }
}

// Функція для визначення групи з найгіршою успішністю
void worst_group(Student students[], int num_students)
{
    double total_scores[4] = {0, 0, 0, 0};
    int count_students[4] = {0, 0, 0, 0};

    for (int i = 0; i < num_students; i++)
    {
        int group = students[i].group - 1;
        total_scores[group] += students[i].web_tech + students[i].ukr_lang + students[i].design_info_systems;
        count_students[group]++;
    }

    double min_avg = total_scores[0] / count_students[0];
    int worst_group = 1;

    for (int i = 1; i < 4; i++)
    {
        if (count_students[i] > 0)
        {
            double avg_score = total_scores[i] / count_students[i];
            if (avg_score < min_avg)
            {
                min_avg = avg_score;
                worst_group = i + 1;
            }
        }
    }

    printf("Group %d\n", worst_group);
}
