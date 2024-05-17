//Pisca LED 
#include "esp_err.h"
#include "driver/gpio.h" //Funcionamento do GPIO
#include "driver/ledc.h"
#include "esp_log.h"

#include <freertos/FreeRTOS.h>
#include "freertos/task.h"
#include "esp_system.h"

#define GPIO_OUTPUT_PIN     GPIO_NUM_14

void app_main() {
    // Inicializando um pino GPIO como output
    gpio_set_direction(GPIO_OUTPUT_PIN, GPIO_MODE_OUTPUT);

    gpio_set_level(GPIO_OUTPUT_PIN, 1); // Define ouput para high
    gpio_set_level(GPIO_OUTPUT_PIN, 0); // Set output para low

    while (1) {
        gpio_set_level(GPIO_OUTPUT_PIN, 1); //set output pra high
        vTaskDelay(1000 / portTICK_PERIOD_MS); //delay
        
        gpio_set_level(GPIO_OUTPUT_PIN, 0); //set output pra low
        vTaskDelay(1000 / portTICK_PERIOD_MS); //delay
    }
}