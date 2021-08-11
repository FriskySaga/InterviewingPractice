# Project imports
from Cogs.CogEnums import SellbotCogType
from Cogs.SellbotCogTypes.ColdCaller import ColdCaller
from Cogs.SellbotCogTypes.Telemarketer import Telemarketer

SELLBOT_COG_TYPES = \
{
  SellbotCogType.COLD_CALLER:  ColdCaller,
  SellbotCogType.TELEMARKETER: Telemarketer,
}

def makeCog(cogType):
  """Create a Sellbot cog.
  :param cogType: The type of cog to make
  :type cogType: BossbotCogType, CashbotCogType, LawbotCogType, or SellbotCogType
  """
  # Create Sellbot cogs
  if isinstance(cogType, SellbotCogType):
    return SELLBOT_COG_TYPES[cogType]()

  # Bossbot/Cashbot/Lawbot cogs are unsupported
  else:
    logging.error(f'{cogType} is unsupported')
    return NotImplemented

