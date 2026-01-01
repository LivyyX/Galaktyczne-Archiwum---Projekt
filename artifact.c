#include "artifact.h"

const char* status_to_string(Status s){
    switch (s){
        case BEZPIECZNY: return "BEZPIECZNY";
        case NIESTABILNY: return "NIESTABILNY";
        case ZAKAZANY: return "ZAKAZANY";
        case WYMAGA_KWARANTANNY: return "WYMAGA KWARANTANNY";
        case W_TRAKCIE_BADAN: return "W TRAKCIE BADAN";
        default: return "NIEZNANY";
    }
}