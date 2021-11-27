#ifndef ___nbstruct__
#define ___nbstruct__

#define PI 3.14159265
#define WINTER -1
#define SPRING -0.33
#define SUMMER 0.33
#define FALL 1
#define HIGH_FEVER_LESSTHAN -1
#define HIGH_FEVER_MORETHAN 0
#define HIGH_FEVER_NO 1
#define SERVERAL_A_DAY 0.2f
#define EVERY_DAY 0.4f
#define SERVERAL_A_WEEK 0.6f
#define ONCE_A_WEEK 0.8f
#define HARDLY_NEVER 1
#define SH_NEVER -1
#define SH_OCCASIONALLY 0
#define SH_DAILY 1
#define NORMAL_YES 0 // NORMAL / YES
#define ALTERED_NO 1 // ALTERED / NO
#define ALPHA 0.001
typedef struct
{
    float soadata;                    // SEASON OF Analysis
    double aoadata;                   // Age of Analysis
    unsigned short int cddata;        // Childish Disease
    unsigned short int atdata;        // Accident / Serious Trauma
    unsigned short int sidata;        // Surgical Intervention
    short int hfdata;                 // High Fever Last Year
    float alcconsumptdata;            // Freuqnce of alcohol consumption
    short int shdata;                 // smoking habit
    double numhrsitdata;              // Number of hours spent sitting per table
    unsigned short int semendiagdata; // Semen Diagnosis
} Features;

// Features struct except for Age and Number of Hours Spend sitting per day
struct FeatureSet
{
    unsigned int normal_count;  // Number of Normal
    unsigned int altered_count; // Number of altered
    double prob_normal;         // Probability of Normal
    double prob_altered;        // Probability of Normal
};

// Features for Age and Number of Hours Spend sitting per day
struct featuresettn
{
    unsigned int normal_count;  // Number of Normal
    unsigned int altered_count; // Number of altered
    double sum_normal;          // Number of Normal
    double sum_altered;         // Number of altered
    double var_normal;          // Value of Variance
    double var_altered;         // Value of Variance
    double mean_normal;         // Value of Mean
    double mean_altered;        // Value of Mean
};

typedef struct
{
    struct FeatureSet semen_diagnosis;    // Semen Diagnosis Features
    struct FeatureSet winter;             // Season : Winter
    struct FeatureSet spring;             // Season : Spring
    struct FeatureSet summer;             // Season : Summer
    struct FeatureSet fall;               // Season : Fall
    struct FeatureSet cdiseaseyes;        // Childish Disease Yes
    struct FeatureSet cdiseaseno;         // Childish Disease No
    struct FeatureSet accidenttrauma_yes; // Accident / Serious Trauma YES
    struct FeatureSet accidenttrauma_no;  // Accident / Serious Trauma NO
    struct FeatureSet surgical_yes;       // Surgical Intervention YES
    struct FeatureSet surgical_no;        // Surgical Intervention NO
    struct FeatureSet highfever_lttm;     // High Fever last Year : Less than 3 mths ago
    struct FeatureSet highfever_mttm;     // High Fever last Year : More than 3 mths ago
    struct FeatureSet highfever_none;     // High Fever last Year : NO
    struct FeatureSet freqalchstd;        // Frequency of alcohol : Several times a day
    struct FeatureSet freqalchevery;      // Frequency of alcohol : Every day
    struct FeatureSet freqalchstw;        // Frequency of alcohol : Several times a week
    struct FeatureSet freqalchoaw;        // Frequency of alcohol : Once a week
    struct FeatureSet freqalchhardly;     // Frequency of alcohol : hardly or never
    struct FeatureSet smokehabit_never;   // Smoking Habit : Never
    struct FeatureSet smokehabit_occ;     // Smoking Habit : Occasionally
    struct FeatureSet smokehabit_daily;   // Smoking Habit : Daily
    struct featuresettn ageanalysis;      // Age of Analysis
    struct featuresettn numhrsitptable;   // Number of hours sitting per table
} Probability;

typedef struct
{
    short actual_nora;    // Actual Normal or Altered
    short predicted_nora; // predicted Normal Or Altered :  Y | 0 = Normal or Y | 1 = Altered
    int err_count;
    double prob_normal;  // Probability of Normal
    double prob_altered; // Probability of Altered
} Probability_Err;


struct Confusion_Matrix
{
    unsigned int data_count;
    unsigned int true_pos;  // True Positive : No of times predict correctly that patient is not normal
    unsigned int true_neg;  // True Negative : No of times predict wrongly that patient is normal
    unsigned int false_pos; // True Positive : No of times predict correctly that patient is not normal
    unsigned int false_neg; // True Negative : No of times predict wrongly that patient is normal
    double true_posrate;    // When it's actually yes, how often does it predict yes? TP/actual yes
    double false_posrate;   // When it's actually yes, how often does it predict yes? FP/actual no
    double true_negrate;    // When it's actually no, how often does it predict no? TN/actual no == 1 - false_posrate
    double prob_error;      // the probability of error, occurance of how many time the error occurred
};

typedef struct
{
    struct Confusion_Matrix trg_cmatrix[5];
    struct Confusion_Matrix tst_cmatrix[5];
} Confusion_Matrix_Type;
#endif