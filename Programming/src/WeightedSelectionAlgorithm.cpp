#include "WeightedSelectionAlgorithm.h"
#include <vector>

int WeightedSelectionAlgorithm::weightedSelectionAlgorithm(std::vector<Element> &elements, double q) {
//TODO: your Algorithm implementation goes here to calculate the qValue:

    
    int totalweight = elements[0].getWeight();
    int pivot = elements[0].getValue();
    int maxval = elements[0].getValue();
    int weight_subset1 = 0;
    int weight_subset2 = 0;

    std::vector<Element> subset1;
    std::vector<Element> subset2;

    for (int i = 1; i < elements.size(); i++){
	totalweight += elements[i].getWeight();
	if (elements[i].getValue() < pivot){
	    subset1.push_back(elements[i]);
	    weight_subset1 += elements[i].getWeight();
	}
	if (elements[i].getValue() > pivot){ 
	    subset2.push_back(elements[i]);
	    weight_subset2 += elements[i].getWeight();
	}
	if (elements[i].getValue() > maxval) maxval = elements[i].getValue();
    }

    weight_subset1 += elements[0].getWeight();
    weight_subset2 += elements[0].getWeight();

    Element e1(-1, weight_subset1);
    Element e2(maxval+1, weight_subset2);

    // need to account for total weight somehow
    if ((double) weight_subset1 >= q * (double) totalweight && (double) weight_subset2 > (1.-q) * (double) totalweight) return elements[0].getValue();

    if ((double) weight_subset1 < q * (double) totalweight && (double) weight_subset2 > (1.-q) * (double) totalweight){
	subset2.push_back(e1);
       	return WeightedSelectionAlgorithm::weightedSelectionAlgorithm(subset2 ,q);
    }

    if ((double) weight_subset1 >= q * (double) totalweight && (double) weight_subset2 <= (1.-q) * (double) totalweight){
	subset1.push_back(e2);
       	return WeightedSelectionAlgorithm::weightedSelectionAlgorithm(subset1 ,q);
    }
    
    

    
    
}
