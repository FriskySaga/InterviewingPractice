# Project imports
from Cogs.SellbotCog import SellbotCog

class ColdCaller(SellbotCog):
  @property
  def name(self) -> str:
    return 'Cold Caller'

  @property
  def examine(self):
    return "Maybe you ought to block his number."

