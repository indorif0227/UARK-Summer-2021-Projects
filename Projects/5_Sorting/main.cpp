#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

const int HRULE_LENGTH = 105;

// Prints the main menu and changes the user's choice variable in the main method
void mainMenu(int &choice)
{
    cout << string(HRULE_LENGTH, '=') << endl
         << string(HRULE_LENGTH / 4, ' ') << endl
         << "___  ___                      _____            _   _             _               _____ _____ _____ _____  " << endl
         << "|  \\/  |                     /  ___|          | | (_)           | |             |  ___|  _  |  _  |  _  | " << endl
         << "| .  . | ___ _ __ __ _  ___  \\ `--.  ___  _ __| |_ _ _ __   __ _| |_ ___  _ __  |___ \\| |/' | |/' | |/' | " << endl
         << "| |\\/| |/ _ | '__/ _` |/ _ \\  `--. \\/ _ \\| '__| __| | '_ \\ / _` | __/ _ \\| '__|     \\ |  /| |  /| |  /| | " << endl
         << "| |  | |  __| | | (_| |  __/ /\\__/ | (_) | |  | |_| | | | | (_| | || (_) | |    /\\__/ \\ |_/ \\ |_/ \\ |_/ / " << endl
         << "\\_|  |_/\\___|_|  \\__, |\\___| \\____/ \\___/|_|   \\__|_|_| |_|\\__,_|\\__\\___/|_|    \\____/ \\___/ \\___/ \\___/  " << endl
         << "                  __/ |                                                                                   " << endl
         << "                 |___/                                                                                    " << endl
         << string(HRULE_LENGTH, '=') << endl
         << "(1) Two-way Merge Sort" << endl
         << "(2) Three-way Merge Sort" << endl
         << "(3) Quit" << endl
         << "Please select an option >> ";

    cin >> choice;

    // Error Checking
    while (choice < 1 || choice > 3)
    {
        cout << "Sorry, that is not a valid option. Please try again >> ";
        cin >> choice;
    }

    cout << string(HRULE_LENGTH, '-') << endl;
}

// Populates the array with data from a specifiied range
void randomData(int data[], int size, int range)
{
    cout << "Populating array with random data..." << endl;

    // Seeds the random function using the current time
    srand(time(NULL));

    for (int index = 0; index < size; index++)
    {
        data[index] = rand() % range;
    }

    cout << "Array populated with random data" << endl
         << string(HRULE_LENGTH, '-') << endl;
}

// Prints the array
void printData(int data[], int size)
{
    cout << "Printing array values..." << endl;

    for (int index = 0; index < size; index++)
    {
        cout << setw(5) << data[index];

        // Creates a new line after a secified number of entries
        if ((index + 1) % 15 == 0 && index != 0)
        {
            cout << endl;
        }
    }

    cout << endl
         << "Print complete" << endl
         << string(HRULE_LENGTH, '-') << endl;
}

// Classic two way recursive merge sort
void twoWayMergeSort(int data[], int low, int high)
{
    // Check terminating condition
    int range = high - low + 1;
    if (range > 1)
    {
        // Divide the array and sort both halves
        int mid = (low + high) / 2;
        twoWayMergeSort(data, low, mid);
        twoWayMergeSort(data, mid + 1, high);

        // Create temporary array for merged data
        int *copy = new int[range];

        // Initialize array indices
        int index1 = low;
        int index2 = mid + 1;
        int index = 0;

        // Merge smallest data elements into copy array
        while (index1 <= mid && index2 <= high)
        {
            if (data[index1] < data[index2])
                copy[index++] = data[index1++];
            else
                copy[index++] = data[index2++];
        }

        // Copy any remaining entries from the first half
        while (index1 <= mid)
        {
            copy[index++] = data[index1++];
        }

        // Copy any remaining entries from the second half
        while (index2 <= high)
        {
            copy[index++] = data[index2++];
        }

        // Copy data back from the temporary array
        for (index = 0; index < range; index++)
        {
            data[low + index] = copy[index];
        }
        delete[] copy;
    }
}

// Three way recursive merge sort
void threeWayMerge(int data[], int low, int oneThird, int twoThird, int high, int sorted[])
{
    // cout << "Initialize" << endl;
    // Initialize array indicies
    int index1 = low;
    int index2 = oneThird;
    int index3 = twoThird;
    int index = low;

    // cout << "Merge" << endl;
    // Merge smallest data elements into sorted array
    while (index1 < oneThird && index2 < twoThird && index3 < high)
    {
        if (data[index1] < data[index2])
        {
            if (data[index1] < data[index3])
            {
                sorted[index++] = data[index1++];
            }
            else
            {
                sorted[index++] = data[index3++];
            }
        }
        else
        {
            if (data[index2] < data[index3])
            {
                sorted[index++] = data[index2++];
            }
            else
            {
                sorted[index++] = data[index3++];
            }
        }
        // printData(sorted, index);
    }

    // cout << "Two Left" << endl;
    // If last third runs out
    while (index1 < oneThird && index2 < twoThird)
    {
        if (data[index1] < data[index2])
        {
            sorted[index++] = data[index1++];
            // printData(sorted, index);
        }
        else
        {
            sorted[index++] = data[index2++];
            // printData(sorted, index);
        }
    }

    // If first third runs out
    while ((index2 < twoThird) && (index3 < high))
    {
        if (data[index2] < data[index3])
        {
            sorted[index++] = data[index2++];
            // printData(sorted, index);
        }
        else
        {
            sorted[index++] = data[index3++];
            // printData(sorted, index);
        }
    }

    // If second third runs out
    while (index1 < oneThird && index3 < high)
    {
        if (data[index1] < data[index3])
        {
            sorted[index++] = data[index1++];
            // printData(sorted, index);
        }
        else
        {
            sorted[index++] = data[index3++];
            // printData(sorted, index);
        }
    }
    // printData(sorted, index);

    // cout << "One Left" << endl;
    // Copy any remaining entries from the first third
    while (index1 < oneThird)
    {
        sorted[index++] = data[index1++];
    }

    // Copy any remainnig entries from the second third
    while (index2 < twoThird)
    {
        sorted[index++] = data[index2++];
    }

    // Copy any remaining entries from the last third
    while (index3 < high)
    {
        sorted[index++] = data[index3++];
    }
    // printData(sorted, index);
}

void threeWayMergeSort(int data[], int low, int high, int sorted[])
{
    // cout << "Recurse" << endl;
    // Check terminating condition
    if (high - low <= 1)
    {
        return;
    }

    // Divide array
    int oneThird = low + ((high - low) / 3);
    int twoThird = low + 2 * ((high - low) / 3) + 1;

    // Sorting thirds
    threeWayMergeSort(sorted, low, oneThird, data);
    threeWayMergeSort(sorted, oneThird, twoThird, data);
    threeWayMergeSort(sorted, twoThird, high, data);

    // Merge sorted arrays
    threeWayMerge(data, low, oneThird, twoThird, high, sorted);
}

int main()
{
    int size = -1;
    int range = -1;
    int choice = -1;
    while (choice != 3)
    {
        mainMenu(choice);
        if (choice == 1 || choice == 2)
        {
            // Obtain size and range of random data array from the user
            cout << "Size of array >> ";
            cin >> size;

            while (size < 1)
            {
                cout << "Sorry, that is an invalid size. Please enter a size greater than 0 >> ";
                cin >> size;
            }

            cout << "Range of random values to be stored in the array >> ";
            cin >> range;

            while (range < 0 || range > 1000)
            {
                cout << "Sorry, that is an invalid range. Please enter a range between 0...1000 >> ";
                cin >> range;
            }

            int data[size];

            cout << string(HRULE_LENGTH, '-') << endl;

            // Populates the array with random data
            randomData(data, size, range);
            printData(data, size);

            // Creates a duplicate array for three way merge sort
            int sorted[size];
            for (int index = 0; index < size; index++)
            {
                sorted[index] = data[index];
            }

            // Applying either two-way or three-way merge sort to the data
            if (choice == 1)
            {
                // Get start time
                clock_t time1 = clock();

                cout << "Using Two-way Merge Sort..." << endl;
                twoWayMergeSort(data, 0, size - 1);

                clock_t time2 = clock();
                double run_time = (time2 - time1) / (double)CLOCKS_PER_SEC;

                printData(data, size);

                // Get end time
                cout << fixed << setprecision(3) << "Run time: " << run_time << " seconds\n";
            }
            else if (choice == 2)
            {
                // Get start time
                clock_t time1 = clock();

                cout << "Using Three-way Merge Sort..." << endl;
                threeWayMergeSort(data, 0, size, sorted);

                clock_t time2 = clock();
                double run_time = (time2 - time1) / (double)CLOCKS_PER_SEC;

                printData(sorted, size);

                // Get end time
                cout << fixed << setprecision(3) << "Run time: " << run_time << " seconds\n";
            }

            // Asking the user if they want to proceed and error checking their input
            cout << "Would you like to continue? " << endl
                 << "(1) Yes" << endl
                 << "(2) No" << endl
                 << "Enter your choice here >> ";

            cin >> choice;

            while (choice < 1 || choice > 2)
            {
                cout << "Sorry, that is an invalid choice. Please enter either 1 or 2 >> ";
                cin >> choice;
            }

            if (choice == 2)
            {
                cout << "Thank you for using the Merge Sortinator 5000!" << endl;
                choice = 3;
            }
        }
        else if (choice == 3)
        {
            cout << "Thank you for using the Merge Sortinator 5000!" << endl;
        }
    }
}