//
//
//

const char *opcode_names[] = {
  "LD",   "LDW",  "PUSH",	"PUSHW",  "POP",	  "POPW",   "LDA",	  "LDAR",
	"EX",   "MIRR", "LDI",	"LDIW",   "LDIR",	  "LDIRW",  "LDD",    "LDDW",
  "LDDR", "LDDRW","CPI",	"CPIR",	  "CPD",	  "CPDR", 	"ADD",	  "ADDW",
  "ADC",	"ADCW", "SUB",  "SUBW", 	"SBC",    "SBCW",   "CP",     "CPW",
  "INC",  "INCW", "DEC",  "DECW", 	"NEG",  	"EXTZ",	  "EXTS",	  "DAA",
  "PAA",  "MUL",  "MULS", "DIV",    "DIVS",   "MULA",   "MINC1",  "MINC2",
  "MINC4","MDEC1","MDEC2","MDEC4",  "AND",	  "ANDW",   "OR",     "ORW",
  "XOR",  "XORW", "CPL",  "LDCF",   "STCF",   "ANDCF",  "ORCF",	  "XORCF",
  "RCF",  "SCF",  "CCF",  "ZCF",    "BIT",    "RES",    "SET",    "CHG",
  "TSET", "BS1F", "BS1B", "NOP",    "EI",     "DI",     "SWI",    "HALT",
  "LDC",  "LDX",  "LINK",	"UNLK",	  "LDF",	  "INCF",   "DECF",   "SCC",
  "RLC",  "RRC",  "RL",   "RR",     "SLA",	  "SRA",    "SLL",	  "SRL",
  "RLD",	"RRD",  "JP",   "JR",	    "JRL",	  "CALL",   "CALR",	  "DJNZ",
  "RET",	"RETD",   "RETI",
  "INVALID"
};


const char *R8_names[] = {
    "W","A","B","C","D","E","H","L",
};

const char *R16_names[] = {
    "WA","BC","DE","HL","IX","IY","IZ","SP",
};

const char *R32_names[] = {
    "XWA","XBC","XDE","XhL","XIX","XIY","XIZ","XSP",
};

const char *r8_names[] = {
    "RA0","RW0","QA0","QW0",
    "RC0","RB0","QC0","QB0",
    "RE0","RD0","QE0","QD0",
    "RL0","RH0","QL0","QH0",
    "RA1","RW1","QA1","QW1",
    "RC1","RB1","QC1","QB1",
    "RE1","RD1","QE1","QD1",
    "RL1","RH1","QL1","QH1",
    "RA2","RW2","QA2","QW2",
    "RC2","RB2","QC2","QB2",
    "RE2","RD2","QE2","QD2",
    "RL2","RH2","QL2","QH2",
    "RA3","RW3","QA3","QW3",
    "RC3","RB3","QC3","QB3",
    "RE3","RD3","QE3","QD3",
    "RL3","RH3","QL3","QH3",

    "?","?","?","?", "?","?","?","?", "?","?","?","?", "?","?","?","?",
    "?","?","?","?", "?","?","?","?", "?","?","?","?", "?","?","?","?",
    "?","?","?","?", "?","?","?","?", "?","?","?","?", "?","?","?","?",
    "?","?","?","?", "?","?","?","?", "?","?","?","?", "?","?","?","?",

    "?","?","?","?", "?","?","?","?", "?","?","?","?", "?","?","?","?",
    "?","?","?","?", "?","?","?","?", "?","?","?","?", "?","?","?","?",
    "?","?","?","?", "?","?","?","?", "?","?","?","?", "?","?","?","?",
    "?","?","?","?", "?","?","?","?", "?","?","?","?", "?","?","?","?",
    "?","?","?","?", "?","?","?","?", "?","?","?","?", "?","?","?","?",

    "A'","W'","QA'","QW'",
    "C'","B'","QC'","QB'",
    "E'","D'","QE'","QD'",
    "L'","H'","QL'","QH'",

    "A","W","QA","QW",
    "C","B","QC","QB",
    "E","D","QE","QD",
    "L","H","QL","QH",

    "IXL","IXh","QIXL","QIXh",
    "IYL","IYH","QIYL","QIYH",
    "IZL","IZH","QIZL","QIZH",
    "SPL","SPH","QSPL","QSPH",
};

const char *r16_names[] = {
    "RWA0","?","QWA0","?",
    "RBC0","?","QBC0","?",
    "RDE0","?","QDE0","?",
    "RHL0","?","QHL0","?",
    "RWA1","?","QWA1","?",
    "RBC1","?","QBC1","?",
    "RDE1","?","QDE1","?",
    "RHL1","?","QHL1","?",
    "RWA2","?","QWA2","?",
    "RBC2","?","QBC2","?",
    "RDE2","?","QDE2","?",
    "RHL2","?","QHL2","?",
    "RWA3","?","QWA3","?",
    "RBC3","?","QBC3","?",
    "RDE3","?","QDE3","?",
    "RHL3","?","QHL3","?",

    "?","?","?","?", "?","?","?","?", "?","?","?","?", "?","?","?","?",
    "?","?","?","?", "?","?","?","?", "?","?","?","?", "?","?","?","?",
    "?","?","?","?", "?","?","?","?", "?","?","?","?", "?","?","?","?",
    "?","?","?","?", "?","?","?","?", "?","?","?","?", "?","?","?","?",

    "?","?","?","?", "?","?","?","?", "?","?","?","?", "?","?","?","?",
    "?","?","?","?", "?","?","?","?", "?","?","?","?", "?","?","?","?",
    "?","?","?","?", "?","?","?","?", "?","?","?","?", "?","?","?","?",
    "?","?","?","?", "?","?","?","?", "?","?","?","?", "?","?","?","?",
    "?","?","?","?", "?","?","?","?", "?","?","?","?", "?","?","?","?",

    "WA'","?","QWA'","?",
    "BC'","?","QBC'","?",
    "DE'","?","QDE'","?",
    "HL'","?","QHL'","?",

    "WA","?","QWA","?",
    "BC","?","QBC","?",
    "DE","?","QDE","?",
    "HL","?","QHL","?",

    "IX","?","QIX","?",
    "IY","?","QIY","?",
    "IZ","?","QIZ","?",
    "SP","?","QSP","?",
};


const char *r32_names[] = {
    "XWA0","?","?","?",
    "XBC0","?","?","?",
    "XDE0","?","?","?",
    "XhL0","?","?","?",

    "XWA1","?","?","?",
    "XBC1","?","?","?",
    "XDE1","?","?","?",
    "XhL1","?","?","?",

    "XWA2","?","?","?",
    "XBC2","?","?","?",
    "XDE2","?","?","?",
    "XhL2","?","?","?",

    "XWA3","?","?","?",
    "XBC3","?","?","?",
    "XDE3","?","?","?",
    "XhL3","?","?","?",

    "?","?","?","?", "?","?","?","?", "?","?","?","?", "?","?","?","?",
    "?","?","?","?", "?","?","?","?", "?","?","?","?", "?","?","?","?",
    "?","?","?","?", "?","?","?","?", "?","?","?","?", "?","?","?","?",
    "?","?","?","?", "?","?","?","?", "?","?","?","?", "?","?","?","?",

    "?","?","?","?", "?","?","?","?", "?","?","?","?", "?","?","?","?",
    "?","?","?","?", "?","?","?","?", "?","?","?","?", "?","?","?","?",
    "?","?","?","?", "?","?","?","?", "?","?","?","?", "?","?","?","?",
    "?","?","?","?", "?","?","?","?", "?","?","?","?", "?","?","?","?",
    "?","?","?","?", "?","?","?","?", "?","?","?","?", "?","?","?","?",

    "XWA'","?","?","?",
    "XBC'","?","?","?",
    "XDE'","?","?","?",
    "XhL'","?","?","?",

    "XWA","?","?","?",
    "XBC","?","?","?",
    "XDE","?","?","?",
    "XhL","?","?","?",

    "XIX","?","?","?",
    "XIY","?","?","?",
    "XIZ","?","?","?",
    "XSP","?","?","?",
};

const char *cc_names[] = {
    "F",    "LT",
    "LE",   "ULE",
    "PE",   "MI",
    "EQ/Z", "C/ULT",
    "",      "GE",
    "GT",   "UGT",
    "PO",   "PL",
    "NE/NZ","NC/UGE"
};

const char *cr_names[] = {
    "DMAS0","?","?","?",
    "DMAS1","?","?","?",
    "DMAS2","?","?","?",
    "DMAS3","?","?","?",
    "DMAD0","?","?","?",
    "DMAD1","?","?","?",
    "DMAD2","?","?","?",
    "DMAD3","?","?","?",
    "DMAC0","?","DMAM0","?",
    "DMAC1","?","DMAM1","?",
    "DMAC2","?","DMAM2","?",
    "DMAC3","?","DMAM3","?",
    "INTNEST","?","?","?"
};

const char *addr_names[] = {
    "(XWA)","(XBC)","(XDE)","(XhL)","(XIX)","(XIY)","(XIZ)","(XSP)",
    "(XWA+","(XBC+","(XDE+","(XhL+","(XIX+","(XIY+","(XIZ+","(XSP+",
    "","","",
    "","","","","",""
};