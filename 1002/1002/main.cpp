#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

class term
{
public:
    term() :coefficient(0.0f), exponent(0) {}
    term(float coefficient, int exponent) :coefficient(coefficient), exponent(exponent) {}
    void print() 
    {
        printf("[C:%.1f E:%d]", coefficient, exponent);
    }

    bool operator<(const term& t) const
    {
        return exponent < t.exponent;
    }

    float coefficient;
    int exponent;
};

int main(int argc, char const *argv[])
{
    std::vector<term> pA, pB, result;
    int Ka = 0, Kb = 0;

    scanf("%d", &Ka);
    for(int i = 0; i < Ka; i++)
    {
        float coefficient;
        int exponent;

        scanf("%d %f", &exponent, &coefficient);
        pA.push_back(term(coefficient, exponent));
    }

    scanf("%d", &Kb);
    for(int i = 0; i < Kb; i++)
    {
        float coefficient;
        int exponent;

        scanf("%d %f", &exponent, &coefficient);
        pB.push_back(term(coefficient, exponent));
    }

    // sort
    sort(pA.begin(), pA.end());
    sort(pB.begin(), pB.end());

    ////testing
    //for(int i = 0; i < pA.size(); i++)
    //    pA[i].print();

    //printf("\n");
    //for(int i = 0; i < pB.size(); i++)
    //    pB[i].print();
    //printf("\n");

    // merge
    int i = 0, j = 0;
    while(i < pA.size() && j < pB.size())
    {
        if(pA[i].exponent < pB[j].exponent)
        {
            result.push_back(pA[i]);
            i++;
        }
        else if(pA[i].exponent > pB[j].exponent)
        {
            result.push_back(pB[j]);
            j++;
        }
        else
        {
            // equal
            float coefficient = pA[i].coefficient + pB[j].coefficient;
            if(coefficient != 0)
            {
                result.push_back(term(pA[i].coefficient + pB[j].coefficient, pA[i].exponent));
                i++;
                j++;
            }
            else
            {
                // equal 0 just skip
                i++;
                j++;
            }
        }
    }

    //rest of it
    while(i < pA.size())
    {
        result.push_back(pA[i]);
        i++;
    }

    while(j < pB.size())
    {
        result.push_back(pB[j]);
        j++;
    }

    printf("%d", result.size());
    for(int i = result.size() - 1; i >= 0; i--)
    {
        printf(" %d ", result[i].exponent);
        printf("%.1f", result[i].coefficient);
    }

    //getchar();
    return 0;
}