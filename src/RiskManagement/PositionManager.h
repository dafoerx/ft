// Copyright [2020] <Copyright Kevin, kevin.lau.gd@gmail.com>

#ifndef FT_SRC_RISKMANAGEMENT_POSITIONMANAGER_H_
#define FT_SRC_RISKMANAGEMENT_POSITIONMANAGER_H_

#include "Common/Portfolio.h"
#include "RiskManagement/RiskRuleInterface.h"

namespace ft {

class PositionManager : public RiskRuleInterface {
 public:
  explicit PositionManager(Portfolio* portfolio);

  int check_order_req(const Order* order) override;

  void on_order_sent(const Order* order) override;

  void on_order_traded(const Order* order, int this_traded,
                       double traded_price) override;

  void on_order_canceled(const Order* order, int canceled) override;

  void on_order_rejected(const Order* order, int error_code) override;

 private:
  Portfolio* portfolio_;
};

};  // namespace ft

#endif  // FT_SRC_RISKMANAGEMENT_POSITIONMANAGER_H_
