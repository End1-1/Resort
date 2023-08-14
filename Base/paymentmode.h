#ifndef PAYMENTMODE_H
#define PAYMENTMODE_H

static const char *PAY_DEBIT = "DEBIT";
static const char *PAY_CREDIT = "CREDIT";

enum PAYMENT_MODE {PAYMENT_UNKNOWN = 0,
                   PAYMENT_CASH,
                   PAYMENT_CARD,
                   PAYMENT_BANK,
                   PAYMENT_CL,
                   PAYMENT_ROOM,
                   PAYMENT_COMPLIMENTARY,
                   PAYMENT_DISCOUNT,
                   PAYMENT_TRANSFER,
                   PAYMENT_CREDIT,
                   PAYMENT_ADVANCE,
                   PAYMENT_REFUND,
                   PAYMENT_COUPON,
                   PAYMENT_BARTER,
                   PAYMENT_BREAKFAST,
                   PAYMENT_PAYX,
                   PAYMENT_TERMINAL,
                   PAYMENT_CPAY
                   };


#endif // PAYMENTMODE_H
