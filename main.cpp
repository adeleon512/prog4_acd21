/*
 * prog4_acd21.cpp
 *
 *  Created on: Oct 7, 2013
 *      Author: Adam C. De Leon
 *      NetID: acd21
 *      Program description: This program is intended for use on kiosks in
 *      Fannie's Flower Shop. The flower shop is having a sale on items at
 *      varying discount rates indicated by a colored sticker on each item.
 *      The program allows kiosk to display a menu indicating the category
 *      (vegetable or flower) of seed or bulb and the
 *      rate of discount associated with each color of sticker.
 *      The customer can then select the color of the sticker
 *      on the item they are interested in, enter the regular unit price
 *      indicated on the item and the number of items they want to
 *      purchase. The program then calculates the final price including any
 *      sales tax (rate is 8.25%) and generate a ticket (output file that
 *      could be printed) that displays the item category, quantity
 *      purchased (including unit of measure), discounted price
 *      before sales tax and final price including any sales tax if
 *      the item is taxable.
 */

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {

    ofstream fout;

    // Declare variables and named constants.
    const float SALES_TAX = .0825;
    char choice;
    float list_price;
    float discounted_price;
    float sub_total;
    float final_price;
    int veg_sd_pck;
    int flw_sd_pck;
    float lbs_veg_blb;
    int flw_sd_blb;
    float lbs_veg_sd;

    // Present the sale menu from the console.
    cout << "Fannie Flora's Plant Nursery Sale!" << endl;
    cout << endl;
    cout << "Discount Rates:" << endl;
    cout << endl;
    cout << "A. Red - 10% off taxable flower seeds sold in packets."
         << endl;
    cout << "B. Blue - 20% off non-taxable vegetable seeds sold in packets."
         << endl;
    cout << "C. Yellow - 10% off non-taxable vegetable bulbs sold by the "
            "pound." << endl;
    cout << "D. Green - 10% off taxable flower seed bulbs sold by the bulb."
         << endl;
    cout << "E. Orange - 10% off 2 lbs. or less, or 15% off for more than 2"
            " lbs. of taxable bulk vegetable seeds sold by the pound."
         << endl;
    cout << endl;

    // Prompt the user to enter their desired choice.
    cout << "Please choose from A - E." << endl;
    cin >> choice;

    // Open the output file.
    fout.open("prog4_out_acd21.txt");

    // Setup each option. Prompting the user to enter the list price of each
    // item and the quantity of items desired. Information is then written to
    // an output file presenting the user with the item(s) selected and the
    // quantity of those items selected, as well as, the discounted price and
    // price after tax if any is included.
    switch (choice) {
        case 'a':
        case 'A':
            cout << "Please enter the list price of each flower seed"
                    " packet."
                 << endl;
            cin >> list_price;
            cout << "Please enter the quantity of flower seed packets."
                 << endl;
            cin >> flw_sd_pck;
            fout << setprecision(2) << fixed;
            sub_total = list_price * flw_sd_pck;
            discounted_price = sub_total - (sub_total * .1);
            final_price = discounted_price + (discounted_price *
                                              SALES_TAX);
            fout << "You have selected " << flw_sd_pck << " packet(s) of "
                    "flower seed priced at $" << list_price << " per "
                         "packet." << endl;
            fout << "The discounted price is $" << discounted_price
                 << endl;
            fout << "The final price including tax is $" << final_price
                 << endl;
            break;
        case 'b':
        case 'B':
            cout << "Please enter the list price of each vegetable seed"
                    " packet."
                 << endl;
            cin >> list_price;
            cout << "Please enter the quantity of vegetable seed packets."
                 << endl;
            cin >> veg_sd_pck;
            fout << setprecision(2) << fixed;
            sub_total = list_price * veg_sd_pck;
            discounted_price = sub_total - (sub_total * .2);
            fout << "You have selected " << veg_sd_pck << " packet(s) of"
                    " vegetable seed priced at $" << list_price <<
                 " per packet." << endl;
            fout << "The final price after discount is $"
                 << discounted_price << endl;
            break;
        case 'c':
        case 'C':
            cout << "Please enter the list price per lbs. of vegetable"
                    " bulb." << endl;
            cin >> list_price;
            cout << "Please enter the amount of lbs. of vegetable bulbs."
                 << endl;
            cin >> lbs_veg_blb;
            fout << setprecision(2) << fixed;
            sub_total = list_price * lbs_veg_blb;
            discounted_price = sub_total - (sub_total * .1);
            fout << "You have selected " << lbs_veg_blb << " lbs."
                    " of vegetable seed bulb(s) priced at $"
                 << list_price << " per lbs." << endl;
            fout << "The final price after discount is $"
                 << discounted_price << endl;
            break;
        case 'd':
        case 'D':
            cout << "Please enter the list price of each flower "
                    "seed bulb."
                 << endl;
            cin >> list_price;
            cout << "Please enter the quantity of flower seed bulbs."
                 << endl;
            cin >> flw_sd_blb;
            fout << setprecision(2) << fixed;
            sub_total = list_price * flw_sd_blb;
            discounted_price = sub_total - (sub_total * .1);
            final_price = discounted_price + (discounted_price *
                                              SALES_TAX);
            fout << "You have selected " << flw_sd_blb << " flower seed"
                    " bulb(s) priced at " << list_price << " per bulb."
                 << endl;
            fout << "The discounted price is $" << discounted_price
                 << endl;
            fout << "The final price after tax is $" << final_price
                 << endl;
            break;
        case 'e':
        case 'E':
            cout << "Please enter the list price per pound of"
                    " vegetable seed." << endl;
            cin >> list_price;
            cout << "Please enter the amount of lbs. of bulk vegetable seeds."
                 << endl;
            cin >> lbs_veg_sd;
            fout << setprecision(2) << fixed;
            sub_total = list_price * lbs_veg_sd;

            // Allow for varying discount rates depending on the number of
            // lbs. selected.
            if (lbs_veg_sd <= 2) {
                discounted_price = sub_total - (sub_total * .1);
                fout << "You have selected " << lbs_veg_sd << " lbs. of "
                        "bulk vegetable seeds priced at $" << list_price
                     << " per lbs." << endl;
                fout << "The final price after discount is $"
                     << discounted_price << endl;
            } else if (lbs_veg_sd > 2) {
                discounted_price = sub_total - (sub_total * .15);
                fout << "You have selected " << lbs_veg_sd << " lbs of "
                        "bulk vegetable seeds priced at $" << list_price
                     << " per lbs." << endl;
                fout << "The final price after discount is $"
                     << discounted_price << endl;
            }
            break;
        default:
            fout << choice << " is not a valid choice." << endl;
            break;
    }

    //Instruct the user to check the output file for the results.
    cout << "Please check the output file for results." << endl;

    // Close the output file.
    fout.close();
    return 0;
}

