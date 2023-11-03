 #include <stdio.h>

typedef struct {
    int healthy_count;
    int exchange_count;
    int failed_count;
} BatteryClassification;

BatteryClassification classifyBatteries(int presentCapacityList[], int length) {
    BatteryClassification classification = {0, 0, 0};
    int ratedCapacity = 120;  // Rated capacity of a new battery

    for (int i = 0; i < length; i++) {
        int presentCapacity = presentCapacityList[i];
        float soh = ((float)presentCapacity / ratedCapacity) * 100;

        if (soh > 80) {
            classification.healthy_count++;
        } else if (soh >= 62) {
            classification.exchange_count++;
        } else {
            classification.failed_count++;
        }
    }

    return classification;
}

int main() {
    int presentCapacityList1[] = {113, 116, 80, 95, 92, 70};
    
    int length1 = sizeof(presentCapacityList1) / sizeof(presentCapacityList1[0]);

    BatteryClassification result1 = classifyBatteries(presentCapacityList1, length1);

    printf("Result : Healthy=%d Exchange=%d Failed=%d\n", result1.healthy_count, result1.exchange_count, result1.failed_count);
  
    return 0;
}
