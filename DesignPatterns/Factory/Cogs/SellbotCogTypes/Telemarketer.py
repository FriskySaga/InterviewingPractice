# Project imports
from Cogs.SellbotCog import SellbotCog

class Telemarketer(SellbotCog):
  @property
  def name(self) -> str:
    return 'Telemarketer'

  @property
  def examine(self):
    return "Don't you sign up for his program!"

