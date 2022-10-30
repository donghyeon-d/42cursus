#include <iostream>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
    this->_accountIndex = this->_nbAccounts;
    this->_nbAccounts++;
	this->_amount = initial_deposit;
    this->_totalAmount += this->_amount;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
    this->_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount \
    << ";created" << std::endl;
}

Account::~Account( void )
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount \
    << ";closed" << std::endl;
}

void	Account::_displayTimestamp( void )
{
    std::cout << "[19920104_091532] ";
}
    // std::cout << "account:" << _nbAccounts << ";";
    // std::cout << "account:" << Account::_nbAccounts << ";";

void	Account::displayStatus( void ) const
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex \
    << ";total:" << this->_totalAmount \
    << ";deposits:" << this->_totalNbDeposits \
    << ";withdrawals:" << this->_totalNbWithdrawals \
    << std::endl;
}

void    Account::makeDeposit( int deposit )
{
    this->_nbDeposits++;
    this->_amount += deposit;
    this->_totalAmount += deposit;
    this->_totalNbDeposits++;
}