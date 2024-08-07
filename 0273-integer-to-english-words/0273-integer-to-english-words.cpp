class Solution {
public:
    string printNum(int num) {
        if(num == 1) return "One";
        else if(num == 2) return "Two";
        else if(num == 3) return "Three";
        else if(num == 4) return "Four";
        else if(num == 5) return "Five";
        else if(num == 6) return "Six";
        else if(num == 7) return "Seven";
        else if(num == 8) return "Eight";
        else if(num == 9) return "Nine";
        else if(num == 10) return "Ten";
        else if(num == 11) return "Eleven";
        else if(num == 12) return "Twelve";
        else if(num == 13) return "Thirteen";
        else if(num == 14) return "Fourteen";
        else if(num == 15) return "Fifteen";
        else if(num == 16) return "Sixteen";
        else if(num == 17) return "Seventeen";
        else if(num == 18) return "Eighteen";
        else if(num == 19) return "Nineteen";
        else if(num == 20) return "Twenty";
        else if(num == 30) return "Thirty";
        else if(num == 40) return "Forty";
        else if(num == 50) return "Fifty";
        else if(num == 60) return "Sixty";
        else if(num == 70) return "Seventy";
        else if(num == 80) return "Eighty";
        else if(num == 90) return "Ninety";
        else return ""; 
    }

    string numberToWords(int num) {
        if(num == 0) return "Zero";
        if(num < 20) return printNum(num);

        if(num < 100) {
            string tens = printNum((num / 10) * 10);
            string ones = printNum(num % 10);
            if(ones.empty()) return tens;
            return tens + " " + ones;
        }

        if(num < 1000) {
            string hundreds = printNum(num / 100) + " Hundred";
            string remainder = numberToWords(num % 100);
            if(remainder == "Zero") return hundreds;
            return hundreds + " " + remainder;
        }

        if(num < 1000000) {
            string thousands = numberToWords(num / 1000) + " Thousand";
            string remainder = numberToWords(num % 1000);
            if(remainder == "Zero") return thousands;
            return thousands + " " + remainder;
        }

        if(num < 1000000000) {
            string millions = numberToWords(num / 1000000) + " Million";
            string remainder = numberToWords(num % 1000000);
            if(remainder == "Zero") return millions;
            return millions + " " + remainder;
        }

        string billions = numberToWords(num / 1000000000) + " Billion";
        string remainder = numberToWords(num % 1000000000);
        if(remainder == "Zero") return billions;
        return billions + " " + remainder;
    }
};