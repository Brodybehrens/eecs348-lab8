#include <stdio.h>
#include <ctype.h>

// Read a single character scale (C/F/K)
int read_scale(char *s) {
    char ch;
    if (scanf(" %c", &ch) != 1) return 0;
    ch = toupper(ch);
    if (ch == 'C' || ch == 'F' || ch == 'K') {
        *s = ch;
        return 1;
    }
    return 0;
}

// Validate above absolute zero
int validate_temp(double v, char s) {
    if (s == 'C') return v >= -273.15;
    if (s == 'F') return v >= -459.67;
    if (s == 'K') return v >= 0;
    return 0;
}

// Convert to Celsius
double to_celsius(double v, char from) {
    if (from == 'C') return v;
    if (from == 'F') return (v - 32) * 5.0 / 9.0;
    if (from == 'K') return v - 273.15;
    return 0;
}

// Convert from Celsius
double from_celsius(double c, char to) {
    if (to == 'C') return c;
    if (to == 'F') return c * 9.0 / 5.0 + 32;
    if (to == 'K') return c + 273.15;
    return 0;
}

// Category by Celsius value
const char* get_category(double c) {
    if (c < 0) return "Freezing";
    else if (c < 10) return "Cold";
    else if (c < 25) return "Comfortable";
    else if (c < 35) return "Hot";
    else return "Extreme Heat";
}

// Advisory text
const char* get_advisory(const char *cat) {
    if (cat[0] == 'F') return "Wear a heavy coat.";
    if (cat[0] == 'C' && cat[1] == 'o' && cat[2] == 'l') return "Wear a jacket.";
    if (cat[0] == 'C' && cat[1] == 'o' && cat[2] == 'm') return "Nice out—enjoy!";
    if (cat[0] == 'H') return "Drink lots of water!";
    return "Stay cool and limit outdoor activity.";
}

int main(void) {
    double temp;
    char from, to;

    printf("Enter the temperature value: ");
    if (scanf("%lf", &temp) != 1) {
        printf("Invalid temperature value.\n");
        return 1;
    }

    printf("Enter the original scale (C, F, or K): ");
    if (!read_scale(&from)) {
        printf("Invalid scale.\n");
        return 1;
    }
    if (!validate_temp(temp, from)) {
        printf("Invalid temperature: below absolute zero.\n");
        return 1;
    }

    printf("Enter the scale to convert to (C, F, or K): ");
    if (!read_scale(&to)) {
        printf("Invalid target scale.\n");
        return 1;
    }

    double c = to_celsius(temp, from);
    double converted = from_celsius(c, to);

    // Determine category in Celsius
    double celsius_for_category = to_celsius(converted, to);
    const char* cat = get_category(celsius_for_category);
    const char* advice = get_advisory(cat);

    printf("Converted temperature: %.2f %c\n", converted, to);
    printf("Temperature category: %s\n", cat);
    printf("Weather advisory: %s\n", advice);

    return 0;
}
